/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scrapers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:59:36 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/21 15:43:21 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	check_row(int *row, int v_up, int v_down);
int	check_only_one(int *row);
int	*get_column(int **tab, int j);

int	check_scrapers(int **tab, int *all_views)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_row(tab[i], all_views[8 + i], all_views[12 + i]))
			return (0);
		if (!check_row(get_column(tab, i), all_views[i], all_views[i + 4]))
			return (0);
		i++;
	}
	return (1);
}

int	*get_column(int **tab, int j)
{
	int	*col;
	int	i;

	i = 0;
	col = malloc(sizeof(int) * 4);
	while (i < 4)
	{
		col[i] = tab[i][j];
		i++;
	}
	return (col);
}

int	check_only_one(int *row)
{
	char	only_one[4];
	int		i;

	i = 0;
	while (i++ < 4)
		only_one[i - 1] = 0;
	i = 0;
	while (i++ < 4)
	{
		if (row[i - 1] == 4)
			only_one[3]++;
		if (row[i - 1] == 3)
			only_one[2]++;
		if (row[i - 1] == 2)
			only_one[1]++;
		if (row[i - 1] == 1)
			only_one[0]++;
	}
	i = 0;
	while (i++ < 4)
	{
		if (only_one[i - 1] != 1)
			return (0);
	}
	return (1);
}

int	check_row(int *row, int v_up, int v_down)
{
	int	i;
	int	buffer[2];

	i = 0;
	buffer[0] = 0;
	buffer[1] = 0;
	if (check_only_one(row))
	{
		while (i++ < 4)
		{
			if (row[i - 1] >= buffer[0])
			{
				v_up--;
				buffer[0] = row[i - 1];
			}
			if (row[4 - i] >= buffer[1])
			{
				v_down--;
				buffer[1] = row[4 - i];
			}
		}
		if (v_up == 0 && v_down == 0)
			return (1);
	}
	return (0);
}
