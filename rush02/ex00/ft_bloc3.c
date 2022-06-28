/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bloc3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:04:37 by gmarzull          #+#    #+#             */
/*   Updated: 2021/11/28 20:03:25 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "our_header.h"

int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bloc3(char *s, char **tab)
{
	if (ft_len(s) <= 2)
	{
		ft_bloc2(&s[0], tab);
		return ;
	}
	else if (ft_len(s) == 3 && s[0] == 0)
	{
		ft_bloc2(&s[1], tab);
		return ;
	}
	if (s[0] == '0' && s[1] == '0' && s[2] == '0')
	{
		ft_putchar_trim(tab[0]);
		return ;
	}
	if (s[0] != '0')
	{
		ft_putchar_trim(tab[s[0] - 48]);
		write(1, " ", 1);
		ft_putchar_trim(tab[28]);
		write(1, " ", 1);
	}
	if (!(s[1] == '0' && s[2] == '0'))
		ft_bloc2(&s[1], tab);
}

void	ft_bloc2(char *s, char **tab)
{
	if (ft_len(s) == 1)
		ft_putchar_trim(tab[s[0] - 48]);
	else
	{
		if (s[0] == '0' && s[1] == '0')
			ft_putchar_trim(tab[0]);
		else if (s[0] == '0')
			ft_putchar_trim(tab[s[1] - 48]);
		else if (s[0] == '1')
			ft_putchar_trim(tab[s[1] - 48 + 10]);
		else
		{
			ft_putchar_trim(tab[s[0] - 48 + 18]);
			if (s[1] != '0')
			{
				write(1, " ", 1);
				ft_putchar_trim(tab[s[1] - 48]);
			}
		}
	}
}
