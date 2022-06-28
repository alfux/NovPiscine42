/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:51:00 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/28 20:41:58 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "our_header.h"

char	**get_values(char *dict, char **entries)
{
	unsigned int	i;
	unsigned int	j;
	char			**trad_values;
	char			*buffer;

	i = 0;
	j = 0;
	trad_values = malloc(sizeof(char *) * 41);
	while (i < 41)
	{
		buffer = find_value(dict, entries[i]);
		if (buffer == NULL)
			return (NULL);
		trad_values[i] = malloc(sizeof(char) * (size_value(buffer) + 1));
		strcpy_value(trad_values[i++], buffer);
	}
	free(entries);
	free(dict);
	return (trad_values);
}

void	strcpy_value(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s2[i++] != '\n')
		s1[i - 1] = s2[i - 1];
	s1[i - 1] = '\0';
}

int	size_value(char *value)
{
	unsigned int	i;

	i = 0;
	while (value[i] != '\n')
		i++;
	return (i);
}

char	*find_value(char *dict, char *to_find)
{
	unsigned int	i;
	char			*buffer;

	i = 0;
	while (dict[i++])
	{
		buffer = find_value_in_line(&dict[i - 1], to_find);
		if (buffer != NULL)
			return (buffer);
		while (dict[i - 1] != '\n')
			i++;
	}
	return (NULL);
}

char	*find_value_in_line(char *dict, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (my_isspace(dict[i]))
		i++;
	while (dict[i + j] == to_find[j])
	{
		if (!to_find[++j] && (dict[i + j] == ' ' || dict[i + j] == ':'))
		{
			while (my_isspace(dict[i + j]))
				i++;
			i++;
			while (my_isspace(dict[i + j]))
				i++;
			if (dict[i + j - 1] == '\n')
				return (NULL);
			return (&dict[i + j]);
		}
	}
	return (NULL);
}
