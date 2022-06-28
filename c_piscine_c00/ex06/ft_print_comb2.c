/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:09:59 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/15 12:15:55 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb2(void);
void	write_cmb(int nb1, int nb2);

void	ft_print_comb2(void)
{
	int	i;
	int	nb1;
	int	nb2;

	i = 0;
	nb1 = 0;
	nb2 = 1;
	while (nb1 != 99)
	{
		write_cmb(nb1, nb2);
		nb2++;
		if (nb2 > 99)
		{
			nb1++;
			if (nb1 <= 98)
				nb2 = nb1 + 1;
		}
	}
}

void	write_cmb(int nb1, int nb2)
{
	char	c_nb1[3];
	char	c_nb2[3];

	c_nb1[0] = (nb1 / 10) + 48;
	c_nb1[1] = (nb1 % 10) + 48;
	c_nb1[2] = 0;
	c_nb2[0] = (nb2 / 10) + 48;
	c_nb2[1] = (nb2 % 10) + 48;
	c_nb2[2] = 0;
	write(1, c_nb1, 2);
	write(1, " ", 1);
	write(1, c_nb2, 2);
	if (nb1 <= 97)
		write(1, ", ", 2);
}
