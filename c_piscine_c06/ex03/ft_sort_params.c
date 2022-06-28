/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:56:35 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/25 23:19:48 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		greater_str(char *str1, char *str2);
char	**sort_str(int argc, char **argv);

int	main(int argc, char **argv)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	sort_str(argc, argv);
	while (++i < argc)
	{
		while (argv[i][j])
			write(1, &argv[i][j++], 1);
		j = 0;
		write(1, "\n", 1);
	}
	return (0);
}

int	greater_str(char *str1, char *str2)
{
	unsigned int	i;

	i = 0;
	while (str1[i] && str1[i] == str2[i])
		i++;
	if (str1[i] - str2[i] > 0)
		return (1);
	else
		return (0);
}

char	**sort_str(int argc, char **argv)
{
	char	*str_buffer;
	int		i;

	str_buffer = (char *)0;
	i = 0;
	while (++i < argc - 1)
	{
		if (greater_str(argv[i], argv[i + 1]))
		{
			str_buffer = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = str_buffer;
			i = 0;
		}
	}
	return (argv);
}
