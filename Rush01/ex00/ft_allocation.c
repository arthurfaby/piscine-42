/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:28:36 by afaby             #+#    #+#             */
/*   Updated: 2022/02/27 16:03:02 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

int	ft_str_len(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

int	*init_board(char *params)
{
	int	*board;
	int	i;
	int	border_size;

	border_size = ((ft_str_len(params) + 1) / 2) / 4;
	board = malloc((border_size * border_size) * sizeof (int));
	i = 0;
	while (i < (border_size * border_size))
		board[i++] = 0;
	return (board);
}

int	*init_params(char *str)
{
	int	*params;
	int	i;
	int	param_size;

	param_size = ((ft_str_len(str) + 1) / 2);
	params = malloc((param_size + 1) * sizeof (int));
	i = 0;
	while (i <= param_size)
		params[i++] = 0;
	return (params);
}

void	free_board(int *board)
{
	free(board);
}

void	free_params(int *params)
{
	free(params);
}
