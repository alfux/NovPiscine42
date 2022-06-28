/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:30:12 by afuchs            #+#    #+#             */
/*   Updated: 2021/11/25 19:50:17 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		gen_sol(int board[10][10], int *counter, int j);
int		check_pos_is_free(int board[10][10], int i, int j);
int		check_diags_are_free(int board[10][10], int i, int j);
void	write_board_str(int board[10][10]);

int	ft_ten_queens_puzzle(void)
{
	int	board[10][10];
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
	counter = 0;
	while (i++ < 10)
	{
		while (j < 10)
			board[i - 1][j++] = 0;
		j = 0;
	}
	gen_sol(board, &counter, 0);
	return (counter);
}

void	write_board_str(int board[10][10])
{
	char			str[12];
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (j < 10)
	{
		while (!board[i][j])
			i++;
		str[j++] = '0' + i;
		i = 0;
	}
	str[10] = '\n';
	str[11] = '\0';
	write(1, str, 11);
}

int	gen_sol(int board[10][10], int *counter, int j)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (check_pos_is_free(board, i, j))
		{
			board[i][j] = 1;
			if (j + 1 < 10)
			{
				if (!gen_sol(board, counter, j + 1))
					board[i][j] = 0;
			}
			else
			{
				write_board_str(board);
				board[i][j] = 0;
				*counter += 1;
				return (0);
			}
		}
		i++;
	}
	return (0);
}

int	check_pos_is_free(int board[10][10], int i, int j)
{
	int	x;

	x = 0;
	while (x < 10)
		if (board[i][x++])
			return (0);
	x = 0;
	while (x < 10)
		if (board[x++][j])
			return (0);
	if (check_diags_are_free(board, i, j))
		return (1);
	return (0);
}

int	check_diags_are_free(int board[10][10], int i, int j)
{
	int	y;
	int	x;

	y = i;
	x = j;
	while (y < 10 && x < 10)
		if (board[y++][x++])
			return (0);
	y = i;
	x = j;
	while (y >= 0 && x >= 0)
		if (board[y--][x--])
			return (0);
	y = i;
	x = j;
	while (y >= 0 && x < 10)
		if (board[y--][x++])
			return (0);
	y = i;
	x = j;
	while (y < 10 && x >= 0)
		if (board[y++][x--])
			return (0);
	return (1);
}
