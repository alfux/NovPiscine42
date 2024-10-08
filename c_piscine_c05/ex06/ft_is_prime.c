/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:35:25 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/24 22:54:29 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_prime(int nb)
{
	int	p;

	p = 3;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (!(nb % 2))
		return (0);
	while (p <= nb / p && p++)
		if (!(nb % (p++ - 1)))
			return (0);
	return (1);
}
