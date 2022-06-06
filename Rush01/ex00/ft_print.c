/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:32:56 by vnaud             #+#    #+#             */
/*   Updated: 2022/02/27 11:28:27 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	ft_print_board(int *board, int *params)
{
	int		index;
	char	c;

	index = 0;
	while (index < (size(params)) * (size(params)))
	{
		if ((index % (size(params))) == 0 && index != 0)
			write(1, "\n", 1);
		c = (board[index] + '0');
		write(1, &c, 1);
		if ((index % (size(params))) != (size(params)) - 1)
			write(1, " ", 1);
		index++;
	}
	write(1, "\n", 1);
}
