/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 06:59:02 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/13 11:51:47 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb(void);
void	init_comb(char *comb);
void	write_comb(char *comb);

void	ft_print_comb(void)
{
	char	comb[6];

	init_comb(comb);
	while (comb[0] != '8')
	{
		write_comb(comb);
		comb[2]++;
		if (comb[2] > '9')
		{
			comb[1]++;
			comb[2] = comb[1] + 1;
			if (comb[1] > '8')
			{
				comb[0]++;
				comb[1] = comb[0] + 1;
				comb[2] = comb[1] + 1;
			}
		}
	}
}

void	init_comb(char *comb)
{
	comb[0] = '0';
	comb[1] = '1';
	comb[2] = '2';
	comb[3] = ',';
	comb[4] = ' ';
	comb[5] = 0;
}

void	write_comb(char *comb)
{
	if (comb[0] == '7' && comb[1] == '8' && comb[2] == '9')
		write(1, comb, 3);
	else
		write(1, comb, 5);
}
