/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:40:17 by afuchs            #+#    #+#             */
/*   Updated: 2021/12/01 13:44:02 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_h.h"

int	main(int argc, char **argv)
{
	int		j;
	int		fd;
	char	buff;

	if (argc > 1)
	{
		j = 1;
		while (j < argc)
		{
			ft_map_argv(argv[j]);
			if (j < argc - 1 && argc > 2)
				write (1, "\n", 1);
			j++;
		}
		return (0);
	}
	if (argc == 1)
	{
		fd = open("srcs/temp", O_TRUNC | O_RDWR | O_CREAT, 0777);
		while (read(0, &buff, 1))
			write(fd, &buff, 1);
		close(fd);
		ft_map_stdin("srcs/temp");
	}
	return (0);
}

int	ft_map_stdin(char *stdin)
{
	char			*str_map;
	unsigned int	i;
	t_map			map;
	t_info			info;
	t_coord			max_size;

	str_map = get_map_str(stdin);
	if (str_map == NULL)
		return (write(1, "map error\n", 10));
	if (ft_check_map(str_map, &info) == -1)
		return (write(1, "map error\n", 10));
	ft_init_t_map(str_map, &map);
	max_size.i = min_of(map.lin, map.col);
	max_size.j = max_size.i;
	max_size.k = 1;
	if (is_not_full(map))
		str_map = ft_resolve(str_map, max_size, map, info);
	i = 0;
	while (str_map[i] != '\n')
		i++;
	while (str_map[++i])
		write(1, &str_map[i], 1);
	free(str_map);
	free(map.obst);
	return (0);
}

int	ft_map_argv(char *argv)
{
	char			*str_map;
	unsigned int	i;
	t_map			map;
	t_info			info;
	t_coord			max_size;

	str_map = get_map_str(argv);
	if (str_map == NULL)
		return (write(1, "map error\n", 10));
	if (ft_check_map(str_map, &info) == -1)
		return (write(1, "map error\n", 10));
	ft_init_t_map(str_map, &map);
	max_size.i = min_of(map.lin, map.col);
	max_size.j = max_size.i;
	max_size.k = 1;
	if (is_not_full(map))
		str_map = ft_resolve(str_map, max_size, map, info);
	i = 0;
	while (str_map[i] != '\n')
		i++;
	while (str_map[++i])
		write(1, &str_map[i], 1);
	free(str_map);
	free(map.obst);
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
