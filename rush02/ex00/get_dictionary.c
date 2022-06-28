/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dictionary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:28:20 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/28 15:49:50 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "our_header.h"

int	get_file_size(char *file_name)
{
	int		size;
	int		status;
	int		file_descriptor;
	char	buff;

	size = 0;
	status = 1;
	file_descriptor = open(file_name, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	while (status)
	{
		status = read(file_descriptor, &buff, 1);
		if (status == -1)
			return (0);
		if (status)
			size++;
	}
	if (close(file_descriptor) == -1)
		return (0);
	return (size);
}

char	*get_dictionary(char *file_name)
{
	int		size;
	char	*dict;
	int		fd;

	size = get_file_size(file_name);
	dict = malloc(sizeof(char) * (size + 1));
	if (dict == NULL)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd != -1 && read(fd, dict, size) != -1 && close(fd) != -1)
	{
		dict[size] = '\0';
		if (check_syntaxe(dict))
			return (dict);
	}
	free(dict);
	return (NULL);
}
