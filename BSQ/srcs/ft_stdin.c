/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:49:08 by afaby             #+#    #+#             */
/*   Updated: 2022/03/09 18:34:36 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_header.h"

void	ft_clear_file(char *path)
{
	int		fd;

	fd = open(path, O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		ft_error(MAP_ERROR_MSG);
	close(fd);
}

int	ft_get_nb_lines(char *str)
{
	int		len;
	int		i;
	char	*tmp;
	int		res;

	tmp = malloc(ft_strlen(str) + 1);
	len = ft_strlen(str);
	i = 0;
	while (i < len - 3)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	res = ft_atoi(tmp);
	free(tmp);
	return (res);
}

char	*ft_read_stdin(void)
{
	int		ret;
	char	buffer[BS_STDIN];
	int		fd;
	int		n_lines;
	char	*path;

	path = malloc(ft_strlen(".tmpmap") * sizeof(char) + 1);
	path = ".tmpmap";
	ret = read(0, buffer, BS_STDIN);
	n_lines = ft_get_nb_lines(buffer);
	ft_clear_file(path);
	fd = open(path, O_WRONLY | O_APPEND);
	if (ret == -1 || fd == -1)
		ft_error(MAP_ERROR_MSG);
	while (n_lines >= 0)
	{
		buffer[ret] = '\0';
		write(fd, buffer, ret);
		ret = read(0, buffer, BS_STDIN);
		n_lines--;
	}
	close(fd);
	return (path);
}
