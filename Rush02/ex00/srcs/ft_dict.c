/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:26:30 by afaby             #+#    #+#             */
/*   Updated: 2022/03/06 19:39:47 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_h.h"

#include <stdio.h>

t_data	*create_data(char *str)
{
	t_data	*new;
	char	val[BUFFER_SIZE];
	char	k_c[BUFFER_SIZE];
	int		i;

	i = 0;
	while (*str != ':' && *str != ' ')
	{
		k_c[i] = *str;
		k_c[i++ + 1] = '\0';
		str++;
	}
	while (*str == ' ' || *str == ':')
		str++;
	i = 0;
	while (*str >= 32 && *str <= 126)
	{
		val[i] = *str;
		val[i++ + 1] = '\0';
		str++;
	}
	new = malloc(sizeof(t_data));
	new->value = ft_strdup(val);
	new->key = ft_strdup(k_c);
	return (new);
}

int	count_lines(int fd)
{
	int		lines;
	int		ret;
	char	buffer[2];
	char	buf_line[BUFFER_SIZE];
	int		i;

	i = 0;
	lines = 0;
	ret = read(fd, buffer, 1);
	while (ret != 0)
	{
		buf_line[i] = *buffer;
		buf_line[i + 1] = '\0';
		if (*buffer != '\n')
			i++;
		else
		{
			i = 0;
			if (buf_line[0] != '\n')
				lines++;
			buf_line[0] = '\0';
		}
		ret = read(fd, buffer, 1);
	}
	return (lines);
}

t_data	*create_tab(int n_lines, char **lines)
{
	t_data	*tab;
	t_data	*data_tmp;
	int		i;
	int		n;

	i = 0;
	n = 0;
	tab = malloc((n_lines + 1) * sizeof(t_data));
	while (i < n_lines - 1)
	{
		data_tmp = create_data(lines[i++]);
		tab[n++] = *data_tmp;
	}
	data_tmp = create_data("-1 : NULL");
	tab[n] = *data_tmp;
	return (tab);
}

t_data	*ft_parse(char *path)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	char	**lines;
	int		n_lines;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	n_lines = count_lines(fd);
	close(fd);
	fd = open(path, O_RDONLY);
	read(fd, buffer, BUFFER_SIZE);
	lines = ft_split(buffer, "\n");
	close(fd);
	return (create_tab(n_lines, lines));
}
