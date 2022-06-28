/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 06:59:02 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/15 17:58:42 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_combn(int n);
void	convert_str(char *str_comb, int nb, int n);
int		test_comb(char *comb, int n);

void	ft_print_combn(int n)
{
	char	comb[12];
	int		nb;

	nb = 0;
	convert_str(comb, nb, n);
	if (n > 0 && n < 10)
	{
		while (test_comb(comb, n) != 2)
		{
			if (test_comb(comb, n))
				write(1, comb, n + 2);
			nb++;
			convert_str(comb, nb, n);
		}
		write(1, comb, n);
	}
	else
		write(1, "Wrong argument, n must be 0 < n < 10", 36);
}

void	convert_str(char *str_comb, int nb, int n)
{
	str_comb[n + 2] = 0;
	str_comb[n + 1] = ' ';
	str_comb[n] = ',';
	while (n > 0)
	{
		str_comb[n - 1] = (nb % 10) + 48;
		nb /= 10;
		n--;
	}
}

int	test_comb(char *comb, int n)
{
	int	i;

	i = 0;
	while (comb[i + 1] != ',')
	{
		if (comb[i] >= comb[i + 1])
			return (0);
		i++;
	}
	if (comb[0] == '9' - n + 1)
		return (2);
	else
		return (1);
}
