/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 09:51:35 by afaby             #+#    #+#             */
/*   Updated: 2022/03/06 18:45:33 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_h.h"

int	ft_strcmp(char	*s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) != '\0' && *(s2 + i) != '\0')
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (*(s1 + i) - *(s2 + i));
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

int	ft_strlen(char *str)
{
	int	n;	

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

void	ft_putstr(char *str)
{
	int		n;
	char	g;

	n = 0;
	g = ' ';
	while (str[n] != '\0')
	{
		g = str[n];
		write (1, &g, 1);
		n++;
	}
	write (1, " ", 1);
}
