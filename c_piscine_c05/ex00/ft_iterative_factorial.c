/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:04:04 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/24 13:33:18 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_factorial(int nb)
{
	unsigned int	res;

	res = 1;
	if (nb < 0)
		return (0);
	while (nb-- > 1)
		res *= nb + 1;
	return (res);
}
