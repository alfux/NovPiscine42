/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:40:47 by afuchs            #+#    #+#             */
/*   Updated: 2021/12/02 16:23:17 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

unsigned int	total_size(int size, char **strs, char *sep)
{
	int				i;
	unsigned int	j;
	unsigned int	total_size;

	i = 0;
	j = 0;
	total_size = 0;
	while (i++ < size)
	{
		while (strs[i - 1][j++])
			total_size++;
		j = 0;
	}
	j = 0;
	while (sep[j])
		j++;
	total_size += j * (size - 1);
	return (total_size);
}

void	ultimate_strcat(char *dest, int size, char **srcs, char *sep)
{
	int				i;
	unsigned int	j;
	unsigned int	pos;

	i = 0;
	j = 0;
	pos = 0;
	while (i++ < size)
	{
		while (srcs[i - 1][j])
			dest[pos++] = srcs[i - 1][j++];
		j = 0;
		while (sep[j] && i < size)
			dest[pos++] = sep[j++];
		j = 0;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char			*unisepstr;
	unsigned int	max_size;

	if (size <= 0)
	{
		unisepstr = malloc(sizeof(char));
		if (unisepstr == NULL)
			return (NULL);
		*unisepstr = '\0';
	}
	else if (strs == NULL || sep == NULL)
		return (NULL);
	else
	{
		max_size = total_size(size, strs, sep);
		unisepstr = malloc(sizeof(char) * (max_size + 1));
		if (unisepstr == NULL)
			return (NULL);
		unisepstr[size] = '\0';
		ultimate_strcat(unisepstr, size, strs, sep);
	}
	return (unisepstr);
}
