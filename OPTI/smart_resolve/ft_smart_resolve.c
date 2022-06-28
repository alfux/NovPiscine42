/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_resolve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:51:33 by afuchs            #+#    #+#             */
/*   Updated: 2021/12/01 06:38:59 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_h.h"

int	s_valid_square(t_sqre *sqr, t_map2d map)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	i = sqr->i_u;
	j = sqr->j_l;
	size = sqr->i_d - sqr->i_u + 1;
	while (i <= sqr->i_d)
	{
		while (j <= sqr->j_r)
		{
			if (map.map2d[i][j])
			{
				mod_sqr(sqr, sqr->i_u, j + 1, size);
				return (0);
			}
			j++;
		}
		j = sqr->j_l;
		i++;
	}
	return (1);
}

t_sqre	local_resolve(t_sqre zne, t_map2d map, t_coord size)
{
	t_sqre	sqr;

	mod_sqr(&sqr, zne.i_u, zne.j_l, size.i);
	while (sqr.i_d <= zne.i_d)
	{
		while (sqr.j_r <= zne.j_r)
		{
			if (s_valid_square(&sqr, map))
			{
				if (size.j - size.i > 1)
				{
					mod_coord(&size, (size.i + size.j) / 2, size.j, size.i);
					return (local_resolve(zne, map, size));
				}
				return (sqr);
			}
		}
		mod_sqr(&sqr, sqr.i_u + 1, sqr.j_l, size.i);
	}
	mod_coord(&size, (size.i + size.k) / 2, size.i, size.k);
	return (local_resolve(zne, map, size));
}

void	get_zone(t_sqre *zone, unsigned int i, unsigned int j, t_map2d map)
{
	if (j < map.col)
		zone->j_l = j + 1;
	else
		zone->j_l = map.col;
	if (zone->j_r + map.map2d[i][j] - 2 < map.col + 1)
		zone->j_r += map.map2d[i][j] - 2;
	else
		zone->j_r = map.col;
	zone->i_u = i;
	if (i + map.map2d[i][j] - 2 < map.lin)
		zone->i_d = i + map.map2d[i][j] - 2;
	else
		zone->i_d = map.lin - 1;
}

char	*smart_resolve(char *str)
{
	t_map2d			map;
	t_sqre			zone;
	t_sqre			sqr;
	t_sqre			sol;
	t_coord			max_size;
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;

	init_map2d(str, &map);
	mod_sqr(&sol, 0, 0, 0);
	size = 0;
	i = 0;
	j = 0;
	while (i < map.lin)
	{
		while (j < map.col + 2)
		{
			if (map.map2d[i][j] && map.map2d[i][j] > 1)
			{
				get_zone(&zone, i, j, map);
				max_size.i = min_of(zone.i_d - zone.i_u + 1, zone.j_r - zone.j_l + 1);
				mod_coord(&max_size, max_size.i, max_size.i, 0);
				sqr = local_resolve(zone, map, max_size);
				size = sqr.i_d - sqr.i_d + 1;
				sol = sqr;
			}
			j++;
		}
		j = 0;
		i++;
	}
	mod_sqr(&sol, sol.i_u + 1, sol.j_l, sol.i_d - sol.i_u + 1);
	return (draw_sqre(sol, str, map));
}
