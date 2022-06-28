/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:03:13 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/22 18:41:25 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	if (!to_find[0])
		return (str);
	i = 0;
	j = 0;
	while (str[i++])
	{
		while (str[i - 1 + j] == to_find[j])
		{
			if (!to_find[++j])
				return (&str[i - 1]);
		}
		j = 0;
	}
	return ((void *)0);
}
