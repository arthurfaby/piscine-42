/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:17:40 by rledoux           #+#    #+#             */
/*   Updated: 2022/03/09 19:59:25 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_header.h"

int	check(t_map *map, int pos, int size)
{
	int	i;
	int	j;
	int	row;
	int	col;

	row = map->n_rows;
	col = map->n_cols;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (((row - (pos / row)) < size) || ((col - (pos % col)) < size))
				return (0);
			if (map->board[(pos / row) + i][(pos % col) + j] == map->obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	change_board(t_map *map, int pos, int size)
{
	int	i;
	int	j;
	int	row;
	int	col;

	row = map->n_rows;
	col = map->n_cols;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map->board[(pos / row) + i][(pos % col) + j] = map->full;
			j++;
		}
		i++;
	}
	ft_print_map(map);
}

void	solve(t_map *map, int pos)
{
	int	size_max;
	int	pos_finale;
	int	i;
	int	j;

	size_max = 1;
	i = 0;
	while (i < map->n_rows)
	{
		j = 0;
		while (j < map->n_cols)
		{
			if (check(map, pos, size_max) == 1)
			{
				size_max++;
				pos_finale = pos;
			}
			else
				pos++;
			j++;
		}
		i++;
	}
	change_board(map, pos_finale, size_max - 1);
}
