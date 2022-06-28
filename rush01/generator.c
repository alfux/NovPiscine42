/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:19:24 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/21 23:33:20 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	start_with_1(int **tab);
void	start_with_2(int **tab);
void	start_with_3(int **tab);
void	start_with_4(int **tab);

int	**generator(int *seed)
{
	int	**tab_g;
	int	**tab;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab_g = malloc(sizeof(int *) * 24);
	tab = malloc(sizeof(int *) * 4);
	while (i++ < 4)
		*(tab + i - 1) = malloc(sizeof(int) * 4);
	while (j++ < 24)
		*(tab_g + j - 1) = malloc(sizeof(int) * 4);
	i = 0;
	start_with_1(tab_g);
	start_with_2(tab_g);
	start_with_3(tab_g);
	start_with_4(tab_g);
	while (i++ < 4)
	{
		j = 0;
		while (j++ < 4)
			tab[i - 1][j - 1] = tab_g[seed[i - 1]][j - 1];
	}
	return (tab);
}

void	start_with_1(int **tab)
{
	tab[0][0] = 1;
	tab[0][1] = 2;
	tab[0][2] = 3;
	tab[0][3] = 4;
	tab[1][0] = 1;
	tab[1][1] = 2;
	tab[1][2] = 4;
	tab[1][3] = 3;
	tab[2][0] = 1;
	tab[2][1] = 3;
	tab[2][2] = 2;
	tab[2][3] = 4;
	tab[3][0] = 1;
	tab[3][1] = 3;
	tab[3][2] = 4;
	tab[3][3] = 2;
	tab[4][0] = 1;
	tab[4][1] = 4;
	tab[4][2] = 2;
	tab[4][3] = 3;
	tab[5][0] = 1;
	tab[5][1] = 4;
	tab[5][2] = 3;
	tab[5][3] = 2;
}

void	start_with_2(int **tab)
{
	tab[6][0] = 2;
	tab[6][1] = 1;
	tab[6][2] = 3;
	tab[6][3] = 4;
	tab[7][0] = 2;
	tab[7][1] = 1;
	tab[7][2] = 4;
	tab[7][3] = 3;
	tab[8][0] = 2;
	tab[8][1] = 3;
	tab[8][2] = 4;
	tab[8][3] = 1;
	tab[9][0] = 2;
	tab[9][1] = 3;
	tab[9][2] = 1;
	tab[9][3] = 4;
	tab[10][0] = 2;
	tab[10][1] = 4;
	tab[10][2] = 1;
	tab[10][3] = 3;
	tab[11][0] = 2;
	tab[11][1] = 4;
	tab[11][2] = 3;
	tab[11][3] = 1;
}

void	start_with_3(int **tab)
{
	tab[12][0] = 3;
	tab[12][1] = 1;
	tab[12][2] = 2;
	tab[12][3] = 4;
	tab[13][0] = 3;
	tab[13][1] = 1;
	tab[13][2] = 4;
	tab[13][3] = 2;
	tab[14][0] = 3;
	tab[14][1] = 2;
	tab[14][2] = 4;
	tab[14][3] = 1;
	tab[15][0] = 3;
	tab[15][1] = 2;
	tab[15][2] = 1;
	tab[15][3] = 4;
	tab[16][0] = 3;
	tab[16][1] = 4;
	tab[16][2] = 1;
	tab[16][3] = 2;
	tab[17][0] = 3;
	tab[17][1] = 4;
	tab[17][2] = 2;
	tab[17][3] = 1;
}

void	start_with_4(int **tab)
{
	tab[18][0] = 4;
	tab[18][1] = 1;
	tab[18][2] = 2;
	tab[18][3] = 3;
	tab[19][0] = 4;
	tab[19][1] = 1;
	tab[19][2] = 3;
	tab[19][3] = 2;
	tab[20][0] = 4;
	tab[20][1] = 2;
	tab[20][2] = 3;
	tab[20][3] = 1;
	tab[21][0] = 4;
	tab[21][1] = 2;
	tab[21][2] = 1;
	tab[21][3] = 3;
	tab[22][0] = 4;
	tab[22][1] = 3;
	tab[22][2] = 1;
	tab[22][3] = 2;
	tab[23][0] = 4;
	tab[23][1] = 3;
	tab[23][2] = 2;
	tab[23][3] = 1;
}
