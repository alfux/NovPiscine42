/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:36:16 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/25 17:55:55 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		while (argv[i][j])
			write(1, &argv[i][j++], 1);
		j = 0;
		write(1, "\n", 1);
	}
	return (0);
}
