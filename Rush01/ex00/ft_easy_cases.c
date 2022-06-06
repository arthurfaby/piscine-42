/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:57:18 by afaby             #+#    #+#             */
/*   Updated: 2022/02/27 15:26:08 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	easy_cases_top(int *params, int *board, int column)
{
	int	row;

	row = 0;
	if (params[column] == (size(params)))
	{
		while (row < (size(params)))
		{
			board[(row * (size(params))) + column] = row + 1;
			row++;
		}
	}
	else if (params[column] == 1)
	{
		board[column] = (size(params));
	}
}

void	easy_cases_bottom(int *params, int *board, int column)
{
	int	row;

	row = (size(params)) - 1;
	if (params[column + (size(params))] == (size(params)))
	{
		while (row >= 0)
		{
			board[(row * (size(params))) + column] = (size(params)) - row;
			row--;
		}
	}
	else if (params[column] == 1)
	{
		board[(row * (size(params))) + column] = (size(params));
	}
}

void	easy_cases_left(int *params, int *board, int row)
{
	int	column;

	column = 0;
	if (params[row + 2 * (size(params))] == (size(params)))
	{
		while (column < (size(params)))
		{
			board[(row * (size(params))) + column] = column + 1;
			column++;
		}
	}
	else if (params[row] == 1)
	{
		board[(row * (size(params))) + column] = (size(params));
	}
}

void	easy_cases_right(int *params, int *board, int row)
{
	int	column;

	column = (size(params)) - 1;
	if (params[row + 3 * (size(params))] == (size(params)))
	{
		while (column >= 0)
		{
			board[(row * (size(params))) + column] = (size(params)) - column;
			column--;
		}
	}
	else if (params[row] == 1)
	{
		board[(row * (size(params))) + column] = (size(params));
	}
}

void	easy_cases(int *params, int *board)
{
	int	i;

	i = 0;
	while (i < ((size(params)) * 4))
	{
		if (params[i] == 1 || params[i] == (size(params)))
		{
			if (i < (size(params)))
				easy_cases_top(params, board, i % (size(params)));
			else if (i >= (size(params)) && i < (size(params)) * 2)
				easy_cases_bottom(params, board, i % (size(params)));
			else if (i > (size(params)) * 3)
				easy_cases_right(params, board, i % (size(params)));
			else
				easy_cases_left(params, board, i % (size(params)));
		}
		i++;
	}
}
