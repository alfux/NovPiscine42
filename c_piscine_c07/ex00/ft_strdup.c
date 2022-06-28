/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:18:27 by afuchs            #+#    #+#             */
/*   Updated: 2021/12/02 10:44:46 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	unsigned int	i;
	char			*copy;

	i = 0;
	while (src[i])
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (src[i++])
		copy[i - 1] = src[i - 1];
	copy[i] = src[i];
	return (copy);
}
