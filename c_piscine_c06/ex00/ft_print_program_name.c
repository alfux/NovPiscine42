/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:24:21 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/25 17:37:07 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	unsigned int	name_size;

	name_size = 0;
	while (argv[0][name_size])
		name_size++;
	write(1, argv[0], name_size);
	write(1, "\n", 1);
	return (argc - argc);
}
