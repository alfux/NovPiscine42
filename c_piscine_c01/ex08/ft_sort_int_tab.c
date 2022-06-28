/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:48:16 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/16 16:22:16 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	buffer;

	i = 0;
	buffer = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			buffer = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = buffer;
			i = 0;
		}
		else
			i++;
	}
}
