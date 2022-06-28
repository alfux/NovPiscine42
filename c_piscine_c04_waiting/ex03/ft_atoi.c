/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:30:37 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/24 17:51:50 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	unsigned int	i;
	short			sign;
	int				result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i++] <= '9')
		result = 10 * result + (str[i - 1] - 48);
	return (sign * result);
}
