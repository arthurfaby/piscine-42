/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:56:53 by afaby             #+#    #+#             */
/*   Updated: 2022/03/09 19:59:00 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_header.h"

//char[0] -> empty | char[1] -> obstacle | char[2] -> full
void	ft_get_map_chars(char *chars, char *path)
{
	int		ret;
	char	buffer[10];
	int		i;
	int		fd;

	fd = ft_open_file(path);
	ret = read(fd, buffer, 10);
	if (ret == -1)
		ft_error(MAP_ERROR_MSG);
	i = 0;
	while (buffer[i] != '\n')
		i++;
	chars[2] = buffer[i - 1];
	chars[1] = buffer[i - 2];
	chars[0] = buffer[i - 3];
	close(fd);
}

// sizes[0] -> n_lines | sizes[1] -> n_rows
void	ft_get_map_size(int file_size, int *sizes, char *path)
{
	int		ret;
	char	*buffer;
	int		fd;
	char	**lines;
	int		i;

	fd = ft_open_file(path);
	buffer = malloc(file_size * sizeof(char) + 1);
	ret = read(fd, buffer, file_size);
	if (ret == -1)
		ft_error(MAP_ERROR_MSG);
	buffer[ret] = '\0';
	lines = ft_split(buffer, "\n");
	while (lines[1][i] != '\0')
		i++;
	sizes[1] = i;
	sizes[0] = -1;
	while (*(lines + sizes[0]) != 0)
		sizes[0]++;
	free_double_char(lines);
	free(lines);
	free(buffer);
}

//split to get all lines except the first one that we free (old)
char	**ft_get_map_board(int file_size, int n_rows, char *path)
{
	char	**board;
	char	*old;
	int		fd;
	char	*buffer;
	int		ret;

	buffer = malloc(file_size * sizeof(char) + 1);
	board = malloc((sizeof(char *) + 1) * n_rows);
	fd = ft_open_file(path);
	ret = read(fd, buffer, file_size);
	buffer[ret] = '\0';
	board = ft_split(buffer, "\n");
	old = *board;
	board++;
	free(old);
	free(buffer);
	return (board);
}

t_map	*ft_create_map(char	*path)
{
	t_map	*map;
	int		sizes[2];
	char	chars[3];
	int		file_size;

	sizes[0] = 0;
	sizes[1] = 0;
	map = malloc(sizeof(map));
	if (map == NULL)
		ft_error(MAP_ERROR_MSG);
	file_size = ft_get_file_size(path);
	ft_get_map_size(file_size, sizes, path);
	ft_get_map_chars(chars, path);
	map->n_rows = sizes[0];
	map->n_cols = sizes[1];
	map->empty = chars[0];
	map->obstacle = chars[1];
	map->full = chars[2];
	map->board = ft_get_map_board(file_size, map->n_rows, path);
	return (map);
}
