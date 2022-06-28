/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:49:09 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/24 08:49:09 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	src_size;

	i = 0;
	j = 0;
	src_size = 0;
	while (src[src_size])
		src_size++;
	while (dest[i] && i < size)
		i++;
	if (!size)
		return (size + src_size);
	while (src[j] && i + j < size - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	return (i + src_size);
}
