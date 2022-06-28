/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:56:10 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/30 20:14:41 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_h.h"

void	get_map2d(char *str_map, t_map2d *map)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	map->map2d = malloc(sizeof(unsigned int *) * map->lin);
	while (i < map->lin)
		map->map2d[i++] = malloc(sizeof(unsigned int) * (map->col + 2));
	i = 0;
	j = 1;
	k = 0;
	while (str_map[k] != '\n')
		k++;
	while (str_map[++k])
	{
		while (str_map[k] != '\n')
		{
			if (str_map[k++] == map->emp)
				map->map2d[i][j++] = 0;
			else
				map->map2d[i][j++] = 1;
		}
		j = 1;
		i++;
	}
}

void	pre_resolve(t_map2d *map)
{
	t_coord	ijk;

	ijk.i = 0;
	while (ijk.i < map->lin)
	{
		map->map2d[ijk.i][0] = 1;
		map->map2d[ijk.i++][map->col + 1] = 1;
	}
	mod_coord(&ijk, 0, 0, 0);
	while (ijk.i < map->lin)
	{
		while (ijk.j < map->col + 2)
		{
			if (map->map2d[ijk.i][ijk.j] == 1 && ijk.j)
			{
				map->map2d[ijk.i][ijk.k] += ijk.j - 1 - ijk.k;
				ijk.k = ijk.j;
			}
			ijk.j++;
		}
		mod_coord(&ijk, ijk.i + 1, 0, 0);
	}
}

void	init_map2d(char *str_map, t_map2d *map)
{
	unsigned int	k;
	unsigned int	lines;
	unsigned int	columns;

	k = 0;
	lines = 0;
	columns = 0;
	while (str_map[k] != '\n')
		k++;
	map->emp = str_map[k - 3];
	map->obs = str_map[k - 2];
	map->bsq = str_map[k - 1];
	while (str_map[++k] != '\n')
		columns++;
	k -= columns + 1;
	while (str_map[++k])
		if (str_map[k] == '\n')
			lines++;
	map->lin = lines;
	map->col = columns;
	get_map2d(str_map, map);
	pre_resolve(map);
}
