/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:30:37 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/24 10:22:09 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_valid_base(char *base);

int	my_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

int	belong_to_base(unsigned char c, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
		if (c == base[i++])
			return (1);
	return (0);
}

int	unit_base_to_nbr(char c, char *base)
{
	unsigned int	i;

	i = 0;
	while (c != base[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	i;
	unsigned int	base_size;
	short			sign;
	int				result;

	i = 0;
	base_size = 0;
	sign = 1;
	result = 0;
	if (!ft_valid_base(base))
		return (0);
	while (base[base_size])
		base_size++;
	while (my_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (belong_to_base(str[i++], base))
		result = base_size * result + unit_base_to_nbr(str[i - 1], base);
	return (sign * result);
}

int	ft_valid_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (base[i])
		i++;
	if (i == 0 || i == 1)
		return (0);
	i = 0;
	while (base[i++])
	{
		while (base[i + j++])
		{
			if (base[i - 1] == base[i + j - 1])
				return (0);
		}
		j = 0;
		if (base[i - 1] == '+' || base[i - 1] == '-')
			return (0);
		if (my_isspace(base[i - 1]))
			return (0);
	}
	return (1);
}
