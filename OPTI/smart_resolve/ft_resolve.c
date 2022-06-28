/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:01:50 by afuchs            #+#    #+#             */
/*   Updated: 2021/12/01 02:32:04 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_h.h"

char	*draw_sqre(t_sqre sqr, char *str_map, t_map2d info)
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
