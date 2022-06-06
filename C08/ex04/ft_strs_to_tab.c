/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:57:06 by afaby             #+#    #+#             */
/*   Updated: 2022/03/01 18:00:56 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <errno.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = malloc(ft_strlen(src) * sizeof(char) + 1);
	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

t_stock_str	*create_struct(int p_size, char *p_str)
{
	t_stock_str	*new;
	char		*p_copy;

	new = malloc(sizeof(t_stock_str));
	new->size = p_size;
	new->str = p_str;
	p_copy = ft_strdup(p_str);
	new->copy = p_copy;
	return (new);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ss;
	t_stock_str	*ss_list;
	int			i;

	i = 0;
	ss_list = malloc(ac * sizeof(t_stock_str));
	if (errno)
		return (0);
	while (i < ac)
	{
		ss = create_struct(ft_strlen(*(av + i)), *(av + i));
		*(ss_list + i) = *ss;
		i++;
	}
	if (errno)
		return (0);
	ss = create_struct(0, "\0");
	ss->str = 0;
	*(ss_list + i) = *ss;
	return (ss_list);
}
