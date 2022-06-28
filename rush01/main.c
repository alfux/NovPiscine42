/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:03:57 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/22 14:15:26 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int		*get_views(char *str);
int		check_scrapers(int **tab, int *all_views);
void	increment(int *tab, int pos);
int		**generator(int *seed);
void	output_message(int **tab);

int	main(int argc, char **argv)
{
	int	*views;
	int	i;
	int	j;
	int	**tab;
	int	seed[4];

	j = 0;
	i = 0;
	while (i++ < 4)
		seed[i - 1] = 0;
	i = 0;
	views = get_views(argv[1]);
	while (i++ < 331776)
	{
		tab = generator(seed);
		if (check_scrapers(tab, views))
		{
			output_message(tab);
			return (0);
		}
		increment(seed, 0);
		free(tab);
	}
	write(1, "Error\n", 6);
	return (argc);
}

void	output_message(int **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < 4)
	{
		while (j++ < 3)
		{
			tab[i - 1][j - 1] += '0';
			write(1, &tab[i - 1][j - 1], 1);
			write(1, " ", 1);
		}
		tab[i - 1][j - 1] += '0';
		write(1, &tab[i - 1][j - 1], 1);
		write(1, "\n", 1);
		j = 0;
	}
}

int	*get_views(char *str)
{
	int	i;
	int	*views;

	views = malloc(sizeof(int) * 16);
	i = 0;
	while (str[i])
		i++;
	if (i != 31)
		return (views);
	i = 0;
	while (i++ < 16)
		views[i - 1] = str[(i - 1) * 2] - 48;
	return (views);
}

void	increment(int *seed, int pos)
{
	if (pos < 4)
	{
		seed[pos]++;
		if (seed[pos] > 23)
		{
			seed[pos] = 0;
			increment(seed, pos + 1);
		}
	}
}
