/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:35:24 by ade-bois          #+#    #+#             */
/*   Updated: 2022/06/06 17:50:22 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

int	solve(int *params, int *board, int pos)
{
	int	i;

	if (pos == (size(params) * size(params)))
	{
		ft_print_board(board, params);
		return (1);
	}
	i = 1;
	if (board[pos] != 0)
		if (solve(params, board, pos + 1))
			return (1);
	while (i <= size(params))
	{
		if (check(pos, i, board, params))
		{
			board[pos] = i;
			if (solve(params, board, pos + 1))
				return (1);
		}
		i++;
	}
	board[pos] = 0;
	return (0);
}
