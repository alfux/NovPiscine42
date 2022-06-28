/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:39:59 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/26 22:17:23 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putchar(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i++])
		write(1, str + i - 1, 1);
}

void	ft_putnbr_positiv(int n)
{
	char	c;

	if (n < 10)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		c = n % 10 + 48;
		ft_putnbr_positiv(n / 10);
		write(1, &c, 1);
	}
}

void	write_stock_str(struct s_stock_str *stru)
{
	write(1, stru->str, stru->size);
	write(1, "\n", 1);
	ft_putnbr_positiv(stru->size);
	write(1, "\n", 1);
	ft_putchar((*stru).copy);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while ((*(par + i++)).str != 0)
		write_stock_str(par + i - 1);
}
