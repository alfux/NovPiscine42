/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:01:50 by afuchs            #+#    #+#             */
/*   Updated: 2021/12/01 13:38:17 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_h.h"

int	valid_square(t_sqre *sqr, t_map map)
{
	unsigned int	k;
	unsigned int	mx_sz;

	mx_sz = sqr->i_d - sqr->i_u + 1;
	k = 0;
	while (k++ < map.nb_obs)
	{
		if (map.obst[k - 1].i >= sqr->i_u && map.obst[k - 1].i <= sqr->i_d)
		{
			if (map.obst[k - 1].j >= sqr->j_l && map.obst[k - 1].j <= sqr->j_r)
			{
				mod_sqr(sqr, sqr->i_u, map.obst[k - 1].j + 1, mx_sz);
				return (0);
			}
		}
	}
	return (1);
}

char	*draw_sqre(t_sqre sqr, char *str_map, t_info info)
{
	unsigned int	k;
	t_coord			c_bsq;

	k = 0;
	c_bsq.i = 1;
	c_bsq.j = 1;
	while (str_map[k] != '\n')
		k++;
	while (str_map[++k])
	{
		while (str_map[k] != '\n')
		{
			if (c_bsq.j >= sqr.j_l && c_bsq.j <= sqr.j_r)
				if (c_bsq.i >= sqr.i_u && c_bsq.i <= sqr.i_d)
					str_map[k] = info.bsq;
			k++;
			c_bsq.j++;
		}
		c_bsq.j = 1;
		c_bsq.i++;
	}
	k = 0;
	while (str_map[k] != '\n')
		k++;
	return (str_map);
}

void	mod_sqr(t_sqre *sqr, int i, int j, int size)
{
	sqr->i_u = i;
	sqr->i_d = i + size - 1;
	sqr->j_l = j;
	sqr->j_r = j + size - 1;
}

int	min_of(int n, int m)
{
	if (n <= m)
		return (n);
	else
		return (m);
}

char	*ft_resolve(char *s_map, t_coord m_sz, t_map map, t_info info)
{
	unsigned int	k;
	t_sqre			sqr;

	k = 0;
	mod_sqr(&sqr, 1, 1, m_sz.i);
	while (sqr.i_d <= map.lin)
	{
		while (sqr.j_r <= map.col)
		{
			if (valid_square(&sqr, map))
			{
				if (m_sz.j - m_sz.i > 1)
				{
					mod_coord(&m_sz, (m_sz.i + m_sz.j) / 2, m_sz.j, m_sz.i);
					return (ft_resolve(s_map, m_sz, map, info));
				}
				else
					return (draw_sqre(sqr, s_map, info));
			}
		}
		mod_sqr(&sqr, sqr.i_u + 1, 1, m_sz.i);
	}
	mod_coord(&m_sz, (m_sz.i + m_sz.k) / 2, m_sz.i, m_sz.k);
	return (ft_resolve(s_map, m_sz, map, info));
}
