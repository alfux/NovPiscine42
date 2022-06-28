/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:32:55 by pwolff            #+#    #+#             */
/*   Updated: 2021/11/28 14:42:49 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "our_header.h"

int	ft_init_bis(char **tab)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		tab[i][0] = i + '0';
		tab[i][1] = '\0';
		i++;
	}
	while (i < 20)
	{
		tab[i][0] = '1';
		tab[i][1] = i % 10 + '0';
		tab[i][2] = '\0';
		i++;
	}
	while (i < 28)
	{
		tab[i][1] = '0';
		tab[i][0] = (((i % 10) * 10 + i) % 10) + '2';
		tab[i][2] = '\0';
		i++;
	}
	return (i);
}

void	ft_init(char **tab)
{
	int	i;
	int	j;

	i = ft_init_bis(tab);
	tab[i][0] = '1';
	tab[i][1] = '0';
	tab[i][2] = '0';
	tab[i][3] = '\0';
	i++;
	tab[i][0] = '1';
	tab[i][1] = '0';
	tab[i][2] = '0';
	tab[i][3] = '0';
	tab[i][4] = '\0';
	i++;
	while (i < 41)
	{
		j = 1;
		tab[i][0] = '1';
		while (j <= (i - 28) * 3)
			tab[i][j++] = '0';
		tab[i][j] = '\0';
		i++;
	}
}
/* char tab[41][38] = {"\0","\0"}; */
