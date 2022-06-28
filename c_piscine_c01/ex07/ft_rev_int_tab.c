/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:45:08 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/16 15:41:53 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_rev_int_tab(int *tab, int size)
{
	int	buffer;
	int	i;

	i = 0;
	while (size && i < size)
	{
		buffer = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = buffer;
		i++;
		size--;
	}
}
