/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 09:31:26 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/19 12:02:52 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_hexa_2d(char hx)
{
	unsigned char	buffer;

	buffer = (hx / 16);
	if (buffer <= 9)
		buffer += 48;
	else
		buffer += 87;
	write(1, &buffer, 1);
	buffer = hx % 16;
	if (buffer <= 9)
		buffer += 48;
	else
		buffer += 87;
	write(1, &buffer, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			write(1, "\\", 1);
			write_hexa_2d(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
