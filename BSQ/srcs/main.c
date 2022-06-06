/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:31:12 by afaby             #+#    #+#             */
/*   Updated: 2022/06/06 18:00:26 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_header.h"

void	ft_print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->n_rows - 1)
	{
		j = 0;
		while (j < map->n_cols)
		{
			ft_putchar(map->board[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;
	char	*path;

	if (argc == 1)
	{
		path = ft_read_stdin();
		map = ft_create_map(path);
		solve(map, 0);
		free_struct(map);
		return (0);
	}
	while (argc > 1)
	{
		path = argv[argc - 1];
		map = ft_create_map(path);
		solve(map, 0);
		free_struct(map);
		argc--;
	}
	return (0);
}
