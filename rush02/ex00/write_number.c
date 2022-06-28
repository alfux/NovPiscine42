/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:37:40 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/28 21:42:02 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "our_header.h"

void	write_number(char *nb, char **trad)
{
	unsigned int	nb_blocks;
	unsigned int	i;
	unsigned int	first_block_size;
	unsigned int	j;

	nb_blocks = (ft_len(nb) / 3);
	first_block_size = ft_len(nb) % 3;
	j = 0;
	i = 0;
	if (only_zeros(nb))
		ft_bloc3("0", trad);
	if (first_block_size)
		nb_blocks++;
	if (first_block_size && nb_blocks > 1)
	{
		write_first_rank(&nb[j], trad, first_block_size, nb_blocks);
		j += first_block_size;
		i++;
	}
	while (i < nb_blocks)
	{
		write_rank(&nb[j], trad, ++i, nb_blocks);
		j += 3;
	}
	free(nb);
}

void	write_rank(char *nb_cut, char **trad, int i, int nb_blocks)
{
	char	*buffer;

	buffer = get_n_char(nb_cut, 3);
	if (!only_zeros(buffer))
	{
		ft_bloc3(buffer, trad);
		if (nb_blocks - i > 0)
		{
			write(1, " ", 1);
			ft_putchar_trim(trad[27 + nb_blocks - i + 1]);
			write(1, " ", 1);
		}
		else
			write(1, "\n", 1);
	}
	else if (i == nb_blocks)
		write(1, "\10\n", 2);
	free(buffer);
}

void	write_first_rank(char *nb_cut, char **trad, int n, int nb_blocks)
{
	char	*buffer;

	buffer = get_n_char(nb_cut, n);
	if (!only_zeros(buffer))
	{
		ft_bloc3(buffer, trad);
		write(1, " ", 1);
		ft_putchar_trim(trad[27 + nb_blocks]);
		write(1, " ", 1);
	}
	free(buffer);
}

char	*get_n_char(char *str, unsigned int n)
{
	char			*new;
	unsigned int	i;

	i = 0;
	new = malloc(sizeof(char) * (n + 1));
	while (i++ < n)
		new[i - 1] = str[i - 1];
	new[i - 1] = '\0';
	return (new);
}

int	only_zeros(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		if (str[i++] != '0')
			return (0);
	return (1);
}
