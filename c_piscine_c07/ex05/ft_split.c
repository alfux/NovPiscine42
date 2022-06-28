/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:10:20 by afuchs            #+#    #+#             */
/*   Updated: 2021/12/02 23:57:46 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_charset(char *str, char *charset)
{
	unsigned int	i;
	unsigned int	c_size;

	i = 0;
	c_size = 0;
	while (charset[c_size])
		c_size++;
	while (i++ < c_size)
		if (str[i - 1] != charset[i - 1])
			return (0);
	return (c_size);
}

int	count_charset(char *str, char *charset)
{
	int	i;
	int	c_size;
	int	nb_charset;

	i = 0;
	nb_charset = 0;
	c_size = is_charset(charset, charset);
	while (str[i])
		if (is_charset(&str[i++], charset))
				nb_charset++;
	return (nb_charset);
}

char	*get_until_charset(char *str, char *charset)
{
	unsigned int	i;
	char			*str_bit;

	i = 0;
	while (!is_charset(&str[i], charset) && str[i])
		i++;
	str_bit = malloc(sizeof(char) * (i + 1));
	if (str_bit == NULL)
		return (NULL);
	i = 0;
	while (!is_charset(&str[i], charset) && str[i])
	{
		str_bit[i] = str[i];
		i++;
	}
	str_bit[i] = '\0';
	return (str_bit);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_tab;
	int		i;
	int		c_size;
	int		nb_charsets;

	nb_charsets = count_charset(str, charset);
	c_size = is_charset(charset, charset);
	str_tab = malloc(sizeof(char) * (nb_charsets + 2));
	if (str_tab == NULL)
		return (NULL);
	i = 0;
	while (i < nb_charsets + 1)
	{
		str_tab[i] = get_until_charset(str, charset);
		while (!is_charset(str, charset) && *str)
			str++;
		while (is_charset(str, charset))
			str += c_size;
		i++;
	}
	str_tab[i] = 0;
	return (str_tab);
}
