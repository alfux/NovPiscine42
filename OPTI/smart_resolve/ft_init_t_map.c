/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:54:15 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/29 23:02:08 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_h.h"

unsigned int	get_nb_obs(char *map)
{
	unsigned int	i;
	unsigned int	nb_obs;
	char			char_obs;

	i = 0;
	nb_obs = 0;
	while (map[i] != '\n')
		i++;
	char_obs = map[i - 2];
	while (map[++i])
		if (map[i] == char_obs)
			nb_obs++;
	return (nb_obs);
}

void	mod_coord(t_coord *coord, int i, int j, int k)
{
	coord->i = i;
	coord->j = j;
	coord->k = k;
}

t_coord	*get_obs_coords(char *map, unsigned int nb_obs)
{
	unsigned int	k;
	char			char_obs;
	t_coord			pos;
	t_coord			*obst;

	k = 0;
	pos.i = 1;
	pos.j = 1;
	obst = malloc(sizeof(t_coord) * nb_obs);
	while (map[k] != '\n')
		k++;
	char_obs = map[k - 2];
	while (map[++k])
	{
		if (map[k] == char_obs)
			mod_coord(&obst[nb_obs-- - 1], pos.i, pos.j, pos.k);
		if (map[k] == '\n')
			mod_coord(&pos, ++pos.i, 1, pos.k);
		else
			mod_coord(&pos, pos.i, ++pos.j, pos.k);
	}
	return (obst);
}

void	ft_init_t_map(char *str_map, t_map *map)
{
	unsigned int	k;
	unsigned int	lines;
	unsigned int	columns;

	k = 0;
	lines = 0;
	columns = 0;
	while (str_map[k] != '\n')
		k++;
	while (str_map[++k] != '\n')
		columns++;
	k -= columns + 1;
	while (str_map[++k])
		if (str_map[k] == '\n')
			lines++;
	map->lin = lines;
	map->col = columns;
	map->nb_obs = get_nb_obs(str_map);
	map->obst = get_obs_coords(str_map, map->nb_obs);
}
