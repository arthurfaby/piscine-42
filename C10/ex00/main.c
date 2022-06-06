/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:33:18 by afaby             #+#    #+#             */
/*   Updated: 2022/06/06 17:45:40 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_display_file(int fd, char *buffer)
{
	int	ret;

	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret != 0)
	{
		buffer[ret] = '\0';
		ft_putstr(buffer);
		ret = read(fd, buffer, BUFFER_SIZE);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];

	if (argc == 1)
	{
		ft_putstr(ERR_NO_ARGS);
		return (-1);
	}
	if (argc > 2)
	{
		ft_putstr(ERR_TM_ARGS);
		return (-2);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(ERR_NOT_READABLE);
		return (-3);
	}
	ft_display_file(fd, buffer);
	close(fd);
}
