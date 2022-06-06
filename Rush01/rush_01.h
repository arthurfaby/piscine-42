/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:20:05 by vnaud             #+#    #+#             */
/*   Updated: 2022/02/27 16:52:14 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_01_H
# define RUSH_01_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		*init_board(char *params);
int		*init_params(char *params);
void	free_board(int *board);
void	free_params(int *params);
void	ft_print_error(void);
int		ft_check_error(char *str);
void	ft_convert_param(char *str, int *tab);
void	ft_print_board(int *board, int *params);
void	easy_cases(int *params, int *board);
void	easy_cases_top(int *params, int *board, int column);
void	easy_cases_bottom(int *params, int *board, int column);
void	easy_cases_left(int *params, int *board, int row);
void	easy_cases_right(int *params, int *board, int row);
int		solve(int *params, int *board, int pos);
int		check(int pos, int i, int *board, int *params);
int		top_is_ok(int pos, int nb, int *board, int *params);
int		bottom_is_ok(int pos, int nb, int *board, int *params);
int		left_is_ok(int pos, int nb, int *board, int *params);
int		right_is_ok(int pos, int nb, int *board, int *params);
int		ft_str_len(char *str);
int		size(int *params);
int		get_view_top(int pos, int nb, int *board, int *params);
int		get_view_bottom(int pos, int nb, int *board, int *params);
int		get_view_left(int pos, int nb, int *board, int *params);
int		get_view_right(int pos, int nb, int *board, int *params);

#endif
