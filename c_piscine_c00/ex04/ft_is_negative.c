/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 06:46:37 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/15 16:32:35 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int n);

void	ft_is_negative(int n)
{
	char	np;

	if (n < 0)
	{
		np = 'N';
	}
	else
	{
		np = 'P';
	}
	write(1, &np, 1);
}
