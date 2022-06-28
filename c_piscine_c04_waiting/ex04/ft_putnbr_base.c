/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:23:39 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/24 10:12:27 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_in_base(unsigned int nbr, char *base, unsigned int size);

int	valid_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (base[i])
		i++;
	if (i == 0 || i == 1)
		return (0);
	i = 0;
	while (base[i++])
	{
		while (base[i + j++])
		{
			if (base[i - 1] == base[i + j - 1])
				return (0);
		}
		j = 0;
	}
	i = 0;
	while (base[i++])
		if (base[i - 1] == '+' || base[i - 1] == '-')
			return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_size;

	base_size = 0;
	if (valid_base(base))
	{
		while (base[base_size])
			base_size++;
		if (nbr < 0)
		{
			write(1, "-", 1);
			write_in_base(-1 * nbr, base, base_size);
		}
		else
			write_in_base(nbr, base, base_size);
	}
}

void	write_in_base(unsigned int nbr, char *base, unsigned int size)
{
	unsigned int	i;

	i = nbr % size;
	if (nbr >= size)
		write_in_base(nbr / size, base, size);
	write(1, base + i, 1);
}
