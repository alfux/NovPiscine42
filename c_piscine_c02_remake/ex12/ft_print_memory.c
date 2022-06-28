/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:26:40 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/19 12:07:32 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_hexa(unsigned long long int_value, unsigned char nb_digit);
void	print_addr_and_middle(unsigned char *str, unsigned int size);
void	print_str_and_points(unsigned char *str, unsigned int size);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	unsigned char		*str;

	i = 0;
	str = (unsigned char *)addr;
	while (i < size)
	{
		print_addr_and_middle(&str[i], size - i);
		print_str_and_points(&str[i], size - i);
		i += 16;
	}
	return (addr);
}

void	print_str_and_points(unsigned char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && i < size)
	{
		if (str[i] < 32 || str[i] >= 127)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	if (i < size)
		write(1, "\n", 1);
}

void	print_addr_and_middle(unsigned char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	print_hexa((unsigned long long)str, 16);
	write(1, ": ", 2);
	while (i < 16 && i < size)
	{
		print_hexa((unsigned long long)str[i], 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	print_hexa(unsigned long long int_value, unsigned char nb_digit)
{
	unsigned long long	digit;
	unsigned char		buffer;
	unsigned char		i;

	digit = 1;
	buffer = 0;
	i = nb_digit - 1;
	while (i--)
		digit *= 16;
	i = nb_digit;
	while (i)
	{
		buffer = (int_value / digit) % 16;
		if (buffer <= 9)
			buffer += 48;
		else if (buffer >= 10)
			buffer += 87;
		write(1, &buffer, 1);
		digit /= 16;
		i--;
	}
}
