/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:19:01 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/14 17:22:13 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	rush(int x, int y);
void	ft_putchar(char c);
void	line_h(int x);
void	line_m(int x);
void	line_b(int x);

//Write square
void	rush(int x, int y)
{
	int	i;

	i = 1;
	while (i >= 1 && i <= y)
	{
		if (i == 1)
			line_h(x);
		else if (i > 1 && i < y)
			line_m(x);
		else
			line_b(x);
		i++;
	}
}

//Write higher line
void	line_h(int x)
{
	int	j;

	j = 2;
	ft_putchar('/');
	while (j > 1 && j <= x)
	{
		if (j < x)
			ft_putchar('*');
		else
			ft_putchar(92);
		j++;
	}
	ft_putchar('\n');
}

//Write middle line
void	line_m(int x)
{
	int	j;

	j = 1;
	while (j >= 1 && j <= x)
	{
		if (j > 1 && j < x)
			ft_putchar(' ');
		else
			ft_putchar('*');
		j++;
	}
	ft_putchar('\n');
}

//Write bottom line
void	line_b(int x)
{
	int	j;

	j = 2;
	ft_putchar(92);
	while (j > 1 && j <= x)
	{
		if (j < x)
			ft_putchar('*');
		else
			ft_putchar('/');
		j++;
	}
	ft_putchar('\n');
}
