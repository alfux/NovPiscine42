/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:06:46 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/25 19:26:18 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isprime(int nb)
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

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (!(nb % 2))
		nb++;
	if (ft_isprime(nb))
		return (nb);
	else
		return (ft_find_next_prime(nb + 2));
}
