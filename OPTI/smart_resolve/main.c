/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:40:17 by afuchs            #+#    #+#             */
/*   Updated: 2021/12/01 02:37:10 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_h.h"
#include <stdio.h>

int	main(void)
{
	char			*str_map;

	str_map = smart_resolve(get_map_str("TESTS"));
	printf("%s\n", str_map);
	return (0);
}

int	get_file_size(char *file_name)
{
	char			buff;
	int				stat;
	int				fd;
	unsigned int	size;

	size = 0;
	stat = 1;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	while (stat)
	{
		stat = read(fd, &buff, 1);
		if (stat == -1)
			return (0);
		if (stat)
			size++;
	}
	if (close(fd) == -1)
		return (0);
	return (size);
}

char	*get_map_str(char *file_name)
{
	int		size;
	char	*map;
	int		fd;

	size = get_file_size(file_name);
	map = malloc(sizeof(char) * (size + 1));
	if (map == NULL)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd != -1 && read(fd, map, size) != -1 && close(fd) != -1)
	{
		map[size] = '\0';
		return (map);
	}
	free(map);
	return (NULL);
}
