/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:08:52 by afaby             #+#    #+#             */
/*   Updated: 2022/03/09 14:20:55 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_header.h"

int	ft_atoi(char *str)
{
	int		value;
	int		cn;

	value = 0;
	cn = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			cn++;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		value = (value * 10) + (*str - 48);
		str++;
	}
	if (cn % 2)
		return (-value);
	return (value);
}
