/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:43:53 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/26 21:16:04 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <stdlib.h>

int	str_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*str_cpy(char *str)
{
	char			*cpy;
	unsigned int	i;

	i = 0;
	cpy = malloc(sizeof(char) * (str_len(str) + 1));
	*(cpy + str_len(str)) = '\0';
	while (*(str + i++))
		*(cpy + i - 1) = *(str + i - 1);
	return (cpy);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	t_stock_str		*tab;

	i = 0;
	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	while (i++ < ac)
	{
		(*(tab + i - 1)).size = str_len(*(av + i - 1));
		(*(tab + i - 1)).str = *(av + i - 1);
		(*(tab + i - 1)).copy = str_cpy((*(tab + i - 1)).str);
	}
	(*(tab + i - 1)).str = 0;
	(*(tab + i - 1)).copy = (*(tab + i - 1)).str;
	(*(tab + i - 1)).size = 0;
	return (tab);
}
