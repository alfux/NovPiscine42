/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:41:23 by afuchs            #+#    #+#             */
/*   Updated: 2021/12/02 12:37:32 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (NULL);
	i = 0;
	tab = malloc(sizeof(int) * (max - min));
	if (tab == NULL)
		return (NULL);
	while (i++ < max - min)
		tab[i - 1] = min + i - 1;
	return (tab);
}
