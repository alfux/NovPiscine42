/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:51:59 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/28 22:51:29 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "our_header.h"

int	main(int argc, char **argv)
{
	char			**entries;
	unsigned int	i;
	char			**values;

	i = 0;
	entries = malloc(sizeof(char *) * 41);
	while (i++ < 41)
		entries[i - 1] = malloc(sizeof(char) * 38);
	ft_init(entries);
	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (argc == 2)
		if (check_err("default.dict", argv[1], entries, &values))
			write_number(isolate_number(argv[1]), values);
	if (argc == 3)
		if (check_err(argv[1], argv[2], entries, &values))
			write_number(isolate_number(argv[2]), values);
	free(values);
	return (0);
}

int	check_err(char *file_name, char *uint, char **entries, char ***value)
{
	char	*dict;

	if (is_valid_uint(uint) == 1)
		uint = isolate_number(uint);
	else
	{
		if (is_valid_uint(uint) == 2)
			write(1, "Dict Error\n", 11);
		else
			write(1, "Error\n", 6);
		return (0);
	}
	dict = get_dictionary(file_name);
	if (dict == NULL)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	*value = get_values(dict, entries);
	if (*value == NULL)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}

int	is_valid_uint(char *str)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = 0;
	while (my_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (my_isspace(str[i]))
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i++] <= '9')
		size++;
	if (!my_isspace(str[i]) && str[i])
		return (0);
	while (my_isspace(str[i]))
		i++;
	if (!str[i] && size <= 37)
		return (1);
	else if (!str[i] && size > 37)
		return (2);
	return (0);
}

char	*isolate_number(char *str)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;
	char			*isolated;

	i = 0;
	j = 0;
	size = 0;
	while (my_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i++] <= '9')
		size++;
	isolated = malloc(sizeof(char) * (size + 1));
	i -= size;
	while (j++ < size)
		isolated[j - 1] = str[i + j - 1];
	isolated[j - 1] = '\0';
	return (isolated);
}
