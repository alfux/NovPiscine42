/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurst <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:06:24 by jdurst            #+#    #+#             */
/*   Updated: 2021/12/01 14:08:02 by jdurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int	ft_check_map(char *map, t_info *info)
{
	int	l;

	l = ft_firstline(map);
	if (l == -1)
		return (-1);
	info->empty = map[l - 3];
	info->obs = map[l - 2];
	info->bsq = map[l - 1];
	info->lines = ft_lines_nbr(map, l);
	if (ft_check_lines(map, *info) == -1)
		return (-1);
	else
		return (0);
}

int	ft_firstline(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n' && map[i])
	{
		if (map[i] < 32 || map[i] > 126)
			return (-1);
		i++;
	}
	if (i <= 3)
		return (-1);
	if (map[0] > '9' || map[0] < '1')
		return (-1);
	if (map[i] == map[i -1] || map[i] == map[i - 2] || map[i - 1] == map[i - 2])
		return (-1);
	return (i);
}

int	ft_lines_nbr(char *map, int l)
{
	int	i;
	int	out;

	out = 0;
	i = 0;
	while (map[i] && i < l - 3)
	{
		out *= 10;
		out += map[i] - '0';
		i++;
	}
	return (out);
}

int	ft_check_lines(char *map, t_info info)
{
	int	i;
	int	temp;
	int	l;

	i = 1;
	l = 0;
	while (map[i - 1] != '\n' && map[i])
		i++;
	temp = i;
	while (map[temp] != '\n' && map[i])
	{
		temp++;
		l++;
	}
	while (map[i] != '\0')
		if (ft_check_lines2(map, &info, l, &i) == -1)
			return (-1);
	if (info.lines != 0)
		return (-1);
	return (0);
}

int	ft_check_lines2(char *map, t_info *info, int l, int *start)
{
	int	temp;
	int	i;

	i = *start;
	temp = 0;
	while (map[i] != '\n' && map[i])
	{
		if (map[i] != info->empty && map[i] != info->obs)
			return (-1);
		i++;
		temp++;
	}
	if (l != temp)
		return (-1);
	i++;
	info->lines--;
	*start = i;
	return (0);
}
