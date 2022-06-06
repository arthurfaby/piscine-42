/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:38:35 by afaby             #+#    #+#             */
/*   Updated: 2022/02/24 10:09:14 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_board(int board[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(board[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int	check(int x, int y, int board[10])
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (board[i] == y)
			return (0);
		if (i + board[i] == x + y)
			return (0);
		if (i - board[i] == x - y)
			return (0);
		i++;
	}
	return (1);
}

int	solve(int board[10], int pos, int *possibilities)
{
	int	i;

	if (pos == 10)
	{
		*possibilities += 1;
		print_board(board);
		return (1);
	}
	i = 0;
	while (i < 10)
	{
		if (check(pos, i, board))
		{
			board[pos] = i;
			solve(board, pos + 1, possibilities);
		}
		i++;
	}	
	return (1);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	i;
	int	possibilities;

	i = 0;
	possibilities = 0;
	while (i < 10)
	{
		board[i] = -1;
		i++;
	}	
	solve(board, 0, &possibilities);
	return (possibilities);
}
