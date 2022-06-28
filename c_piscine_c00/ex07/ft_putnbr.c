/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:51:21 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/15 17:39:47 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(int nb);
long	power(int n, unsigned int p);

void	ft_putnbr(int nb)
{
	char	digit;
	int		nb_digits;

	digit = 0;
	nb_digits = 1;
	if (nb < 0)
		write(1, "-", 1);
	while (nb / power(10, nb_digits) != 0)
		nb_digits++;
	while (nb_digits >= 1)
	{
		digit = ((nb / power(10, nb_digits - 1)) % 10);
		if (nb < 0)
			digit *= -1;
		digit += 48;
		write(1, &digit, 1);
		nb_digits--;
	}
}

long	power(int n, unsigned int p)
{
	long	result;

	result = 1;
	while (p >= 1)
	{
		result = result * n;
		p--;
	}
	return (result);
}
