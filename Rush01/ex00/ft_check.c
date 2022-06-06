/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psyrot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:28:37 by psyrot            #+#    #+#             */
/*   Updated: 2022/02/27 16:50:31 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush_01.h"

int	top_is_ok(int pos, int nb, int *board, int *params)
{
	int	view;
	int	col;

	view = get_view_top(pos, nb, board, params);
	col = pos % size(params);
	if ((view <= params[col]
			&& pos < size(params) * (size(params) - 1))
		|| (view == params[col]
			&& pos >= size(params) * (size(params) - 1)))
		return (1);
	return (0);
}

int	bottom_is_ok(int pos, int nb, int *board, int *params)
{
	int	view;
	int	col;

	col = pos % (size(params));
	view = get_view_bottom(pos, nb, board, params);
	if (view == params[col + (size(params))])
		return (1);
	return (0);
}

int	left_is_ok(int pos, int nb, int *board, int *params)
{
	int	view;
	int	row;

	row = pos / size(params);
	view = get_view_left(pos, nb, board, params);
	if ((view <= params[row + (2 * (size(params)))]
			&& (pos % (size(params))) < ((size(params)) - 1))
		|| (view == params[row + (2 * size(params))]
			&& (pos % (size(params))) >= ((size(params)) - 1)))
		return (1);
	return (0);
}

int	right_is_ok(int pos, int nb, int *board, int *params)
{
	int	view;
	int	row;

	row = pos / (size(params));
	view = get_view_right(pos, nb, board, params);
	if (view == params[row + (3 * (size(params)))])
		return (1);
	return (0);
}

int	check(int pos, int nb, int *board, int *params)
{
	int	i;

	i = -1;
	while (++i < (size(params)))
	{
		if (board[(pos % (size(params))) + (i * (size(params)))] == nb)
			return (0);
	}
	i = -1;
	while (++i < (size(params)))
	{
		if (board[(pos / (size(params))) * (size(params)) + i] == nb)
			return (0);
	}
	if (!top_is_ok(pos, nb, board, params))
		return (0);
	if (!left_is_ok(pos, nb, board, params))
		return (0);
	if (pos >= (size(params) * (size(params) - 1))
		&& !bottom_is_ok(pos, nb, board, params))
		return (0);
	if ((pos % (size(params))) == ((size(params)) - 1)
		&& !right_is_ok(pos, nb, board, params))
		return (0);
	return (1);
}
