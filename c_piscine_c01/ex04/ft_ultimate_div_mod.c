/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:58:07 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/16 14:02:32 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	buffer;

	buffer = *a;
	if (*b)
		*a = *a / *b;
	if (*b)
		*b = buffer % *b;
}
