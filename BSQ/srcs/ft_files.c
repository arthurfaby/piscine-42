/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:05:19 by afaby             #+#    #+#             */
/*   Updated: 2022/03/09 16:28:40 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_header.h"

int	ft_open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error(MAP_ERROR_MSG);
	return (fd);
}

int	ft_get_file_size(char *path)
{
	int		ret;
	int		fd;
	char	buffer[1];
	int		size;

	fd = ft_open_file(path);
	size = 0;
	ret = read(fd, buffer, 1);
	size++;
	while (ret != 0)
	{
		ret = read(fd, buffer, 1);
		size++;
	}
	close(fd);
	return (size);
}
