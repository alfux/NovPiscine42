/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:40:55 by afuchs            #+#    #+#             */
/*   Updated: 2021/12/02 17:58:16 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_nb_digits(int nb, int base_size)
{
	unsigned int	size;

	if (nb == 0)
		return (1);
	size = 0;
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= base_size;
		size++;
	}
	return (size);
}
