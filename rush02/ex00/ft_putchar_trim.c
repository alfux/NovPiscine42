/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_trim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:27:23 by pwolff            #+#    #+#             */
/*   Updated: 2021/11/28 16:06:12 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_trim(char *tab)
{
	int	i;
	int	test;

	i = 0;
	test = 1;
	while (tab[i])
	{
		if (tab[i] >= 33 && tab[i] <= 126)
		{
			test = 1;
			write (1, &tab[i], 1);
		}
		else if (tab[i] == ' ' && test && tab[i + 1] == '\n')
			test = 0;
		else if (tab[i] == ' ' && test && tab[i + 1] >= 33 && tab[i] <= 126)
		{
			test = 0;
			write (1, &tab[i], 1);
		}
		i++;
	}
}
