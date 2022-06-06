/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundreds2MODIF.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbugnico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:51:22 by jbugnico          #+#    #+#             */
/*   Updated: 2022/03/06 18:58:46 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_h.h"

void	check_if_less_than_twenty(int *i, int *j, t_data *datas, char *str)
{
	if (*j == 1 && str[*j] < '2' && datas[*i].key[1] == str[*j + 1]
		&& str[*j] == datas[*i].key[0] && ft_strcmp(datas[*i].key, "0") != 0)
	{
		ft_putstr(datas[*i].value);
		*j = *j + 2;
		*i = 0;
	}
}

void	check_if_greater_than_twenty(int *i, int *j, t_data *datas, char *str)
{
	if (*j == 1 && str[*j] >= '2' && datas[*i].key[1] == '0'
		&& str[*j] == datas[*i].key[0] && ft_strcmp(datas[*i].key, "0") != 0)
	{
		ft_putstr(datas[*i].value);
		(*j)++;
		*i = 0;
	}
}

void	ft_hundreds(char *str, t_data *datas)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	j = 0;
	while (ft_strcmp(datas[k].key, "-1") && ft_strcmp(datas[k].key, "100"))
		k++;
	while (ft_strcmp(datas[i].key, "-1") && j < 3)
	{
		if (str[j] == '0')
			j++;
		check_if_less_than_twenty(&i, &j, datas, str);
		check_if_greater_than_twenty(&i, &j, datas, str);
		if (str[j] == datas[i].key[0] && (j == 0 || j == 2)
			&& ft_strcmp(datas[i].key, "0") != 0)
		{	
			ft_putstr(datas[i].value);
			if (j++ == 0)
				ft_putstr(datas[k].value);
			i = -1;
		}
		i++;
	}
}
