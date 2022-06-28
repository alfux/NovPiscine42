/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:28:31 by afuchs            #+#    #+#             */
/*   Updated: 2021/12/02 19:16:39 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

unsigned int	get_nb_digits(int nb, int base_size);

int	my_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (base[i++])
	{
		while (base[i + j])
			if (base[i - 1] == base[i + j++])
				return (0);
		j = 0;
		if (my_isspace(base[i]))
			return (0);
		if (base[i - 1] == '+' || base[i - 1] == '-')
			return (0);
	}
	if (i == 1 || i == 2)
		return (0);
	return (i - 1);
}

int	is_in_base(char c, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
		if (c == base[i++])
			return (i);
	return (0);
}

int	ft_atoi_base(char *nbr, char *base)
{
	unsigned int	i;
	int				sign;
	int				res;
	int				base_size;
	int				base_rank;

	base_size = check_base(base);
	if (!base_size)
		return (0);
	i = 0;
	res = 0;
	sign = 1;
	while (my_isspace(nbr[i]))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
		if (nbr[i++] == '-')
			sign *= -1;
	base_rank = is_in_base(nbr[i], base);
	while (base_rank)
	{
		res = base_size * res + base_rank - 1;
		base_rank = is_in_base(nbr[++i], base);
	}
	return (sign * res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	nb_digit;
	int				nb;
	int				i;
	unsigned int	base_size;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	base_size = check_base(base_to);
	nb = ft_atoi_base(nbr, base_from);
	nb_digit = get_nb_digits(nb, base_size);
	nbr = malloc(sizeof(char) * (nb_digit + 1));
	if (nbr == NULL)
		return (NULL);
	if (nb < 0)
		nbr[0] = '-';
	if (nb < 0)
		nb *= -1;
	i = nb_digit - 1;
	while (i >= 0 && nbr[i] != '-')
	{
		nbr[i--] = base_to[nb % base_size];
		nb /= base_size;
	}
	nbr[nb_digit] = '\0';
	return (nbr);
}
