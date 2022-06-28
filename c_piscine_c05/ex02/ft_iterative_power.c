/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:50:12 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/24 13:57:53 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	res = 1;
	while (power--)
		res *= nb;
	return (res);
}
