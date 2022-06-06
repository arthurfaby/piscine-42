/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:44:50 by mcloarec          #+#    #+#             */
/*   Updated: 2022/03/06 20:19:25 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_h.h"

char	*ft_long(int len)
{
	unsigned long long int	var;
	char					*cle;

	if (len % 3 == 0)
		var = len - 3;
	else
		var = len - (len % 3);
	cle = ft_str_power("10", var);
	return (cle);
}

char	*ft_div_char(char *cle)
{
	int	index;
	int	j;

	j = 0;
	index = ft_strlen(cle);
	if (ft_strlen(cle) >= 4)
	{
		while (j < 4)
		{
			cle[index - j] = '\0';
			j++;
		}
	}
	return (cle);
}

char	*ft_remp_tmp(char *tmp, char *str, int len, int *i)
{
	if (len % 3 == 0)
	{
		tmp[0] = str[*i];
		tmp[1] = str[*i + 1];
		tmp[2] = str[*i + 2];
		*i = *i + 3;
	}
	if (len % 3 == 1)
	{
		tmp[0] = '0';
		tmp[1] = '0';
		tmp[2] = str[*i];
		*i = *i + 1;
	}
	if (len % 3 == 2)
	{
		tmp[0] = '0';
		tmp[1] = str[*i];
		tmp[2] = str[*i + 1];
		*i = *i + 2;
	}
	return (tmp);
}
