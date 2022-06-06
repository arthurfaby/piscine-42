/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_particular_cases.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:03:23 by afaby             #+#    #+#             */
/*   Updated: 2022/03/06 19:41:16 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_h.h"

char	*add_zeros(char *str)
{
	int		len;
	char	*new;

	new = malloc(4);
	len = ft_strlen(str);
	if (len < 3)
	{
		if (len == 2)
		{
			new[0] = '0';
			new[1] = str[0];
			new[2] = str[1];
		}
		if (len == 1)
		{
			new[0] = '0';
			new[1] = '0';
			new[2] = str[0];
		}
		new[3] = '\0';
	}
	return (new);
}

int	contains_only_zeros(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

int	check_zero(char *str, t_data *datas)
{
	int		i;
	char	*tmp;

	tmp = str;
	i = 0;
	if (contains_only_zeros(tmp))
	{
		while (ft_strcmp(datas[i].key, "-1") != 0)
		{
			if (ft_strcmp(datas[i].key, "0") == 0)
			{
				ft_putstr(datas[i].value);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
