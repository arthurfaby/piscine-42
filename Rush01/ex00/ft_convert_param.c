/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:44:29 by ade-bois          #+#    #+#             */
/*   Updated: 2022/02/27 16:02:16 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

int	size(int *params)
{
	int	size;

	size = 0;
	while (params[size] != -42)
		size++;
	return (size / 4);
}

void	ft_convert_param(char *str, int *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			tab[j] = str[i - 1] - 48;
			j++;
		}
		i++;
	}
	tab[j] = str[i - 1] - 48;
	tab[++j] = -42;
}
