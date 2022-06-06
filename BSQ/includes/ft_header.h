/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:54:51 by afaby             #+#    #+#             */
/*   Updated: 2022/03/09 20:50:56 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BS_STDIN 256
# define MAP_ERROR_MSG "map error\n"

typedef struct s_map
{
	int		n_rows;
	int		n_cols;
	char	empty;
	char	full;
	char	obstacle;
	char	**board;
}	t_map;

void	change_board(t_map *map, int pos, int size);
void	ft_putchar(char c);
void	ft_puterr(char *str);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_error(char *str);
int		ft_open_file(char *path);
char	**ft_split(char *str, char *charset);
int		ft_get_file_size(char *path);
t_map	*ft_create_map(char *path);
void	solve(t_map *map, int pos);
void	ft_print_map(t_map *map);
void	free_double_char(char **strs);
void	free_struct(t_map *map);
char	*ft_read_stdin(void);
int		ft_atoi(char *str);
int		ft_check_error(char *path);

#endif
