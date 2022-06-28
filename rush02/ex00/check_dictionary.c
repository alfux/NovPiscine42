/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dictionary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 09:27:21 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/28 10:58:05 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "our_header.h"

int	is_printable(char c)
{
	if (c < ' ' || c == 127)
		return (0);
	return (1);
}

int	my_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	check_line_syntaxe(char *str)
{
	unsigned int	i;

	i = 0;
	if (str[i] == '\n')
		return (1);
	while (my_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] == ':')
		i++;
	else
		return (0);
	while (str[i] == ' ')
		i++;
	while (is_printable(str[i]))
		i++;
	if (str[i] == '\n')
		return (i + 1);
	else
		return (0);
}

int	check_syntaxe(char *dict)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dict[i])
	{
		j = check_line_syntaxe(dict + i);
		if (j == 0)
			return (0);
		i += j;
	}
	return (1);
}
