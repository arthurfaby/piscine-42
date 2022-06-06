/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dico.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:35:25 by mcloarec          #+#    #+#             */
/*   Updated: 2022/03/06 20:11:41 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_h.h"

int	ft_check_line(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (ft_print_dict_error());
	while (*str >= '0' && *str <= '9')
		str++;
	while ((*str >= 32 && *str <= 47) || (*str >= 59 && *str <= 126))
		str++;
	if (!(*str == ':'))
		return (ft_print_dict_error());
	while (*str == ':')
		str++;
	while (*str == ' ')
		str++;
	if (!(*str >= 32 && *str <= 126))
		return (ft_print_dict_error());
	while ((*str >= 32 && *str <= 57) || (*str >= 59 && *str <= 126))
		str++;
	if (*str != '\0')
		return (ft_print_dict_error());
	else
		return (0);
}

int	ft_check_dico(char *path)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	char	**lines;
	int		n_lines;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_print_dict_error());
	n_lines = count_lines(fd);
	close(fd);
	fd = open(path, O_RDONLY);
	read(fd, buffer, BUFFER_SIZE);
	lines = ft_split(buffer, "\n");
	close(fd);
	i = 0;
	while (i < n_lines - 1)
	{
		if (ft_check_line(lines[i++]) == 1)
			return (1);
	}
	return (0);
}
