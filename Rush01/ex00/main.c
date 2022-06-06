/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:40:11 by afaby             #+#    #+#             */
/*   Updated: 2022/02/27 16:03:15 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

int	main(int argc, char **argv)
{
	int	*board;
	int	*params;

	if (argc != 2)
	{
		ft_print_error();
		return (1);
	}
	if (ft_check_error(argv[1]) == 1)
	{
		board = init_board(argv[1]);
		params = init_params(argv[1]);
		ft_convert_param(argv[1], params);
	}
	else
	{
		ft_print_error();
		return (2);
	}
	easy_cases(params, board);
	if (!solve(params, board, 0))
		ft_print_error();
	free_board(board);
	free_params(params);
	return (0);
}
