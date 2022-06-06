/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:49:08 by afaby             #+#    #+#             */
/*   Updated: 2022/02/27 16:50:56 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

int	get_view_top(int pos, int nb, int *board, int *params)
{
	int	row;
	int	col;
	int	max;
	int	view;

	view = 0;
	max = 0;
	row = 0;
	col = pos % size(params);
	while (row < size(params) && max != size(params))
	{
		if (pos == (row * size(params) + col) && nb > max)
		{
			max = nb;
			view++;
		}
		else if (board[(row * size(params)) + col] > max)
		{
			max = board[(row * size(params)) + col];
			view++;
		}
		row++;
	}
	return (view);
}

int	get_view_bottom(int pos, int nb, int *board, int *params)
{
	int	row;
	int	col;
	int	max;
	int	view;

	view = 0;
	max = 0;
	row = size(params) - 1;
	col = pos % size(params);
	while (row >= 0 && max != size(params))
	{
		if (pos == (row * size(params) + col) && nb > max)
		{
			max = nb;
			view++;
		}
		else if (board[(row * size(params)) + col] > max)
		{
			max = board[(row * size(params)) + col];
			view++;
		}
		row--;
	}
	return (view);
}

int	get_view_left(int pos, int nb, int *board, int *params)
{
	int	row;
	int	col;
	int	max;
	int	view;

	view = 0;
	max = 0;
	row = pos / size(params);
	col = 0;
	while (col < size(params) && max != size(params))
	{
		if (pos == (row * size(params) + col) && nb > max)
		{
			max = nb;
			view++;
		}
		else if (board[(row * size(params)) + col] > max)
		{
			max = board[(row * size(params)) + col];
			view++;
		}
		col++;
	}
	return (view);
}

int	get_view_right(int pos, int nb, int *board, int *params)
{
	int	row;
	int	col;
	int	max;
	int	view;

	view = 0;
	max = 0;
	col = size(params) - 1;
	row = pos / size(params);
	while (col >= 0 && max != size(params))
	{
		if (pos == (row * size(params) + col) && nb > max)
		{
			max = nb;
			view++;
		}
		else if (board[(row * size(params)) + col] > max)
		{
			max = board[(row * size(params)) + col];
			view++;
		}
		col--;
	}
	return (view);
}
