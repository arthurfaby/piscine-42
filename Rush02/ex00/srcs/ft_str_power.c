/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_power.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbugnico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:51:22 by jbugnico          #+#    #+#             */
/*   Updated: 2022/03/06 18:30:21 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_h.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	ct;

	ct = 0;
	while (src[ct] != '\0')
	{
		dest[ct] = src[ct];
		ct++;
	}
	while (dest[ct] != '\0')
	{
		dest[ct] = '0';
		ct++;
	}
	return (dest);
}

char	*ft_str_power(char *str, int power)
{
	char	*res;
	int		i;
	int		i2;

	i = 1;
	i2 = 0;
	if (power < 0)
		return ("0");
	if (power == 0)
		return ("1");
	while (i < power)
		i++;
	res = malloc(sizeof(char) * (ft_strlen(str) + i));
	res[ft_strlen(str) + i - 1] = '\0';
	while (i2 < ft_strlen(str) + i - 1)
	{
		res[i2] = '-';
		i2++;
	}
	ft_strcpy(res, str);
	return (res);
}
