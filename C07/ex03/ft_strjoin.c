/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:07:59 by afaby             #+#    #+#             */
/*   Updated: 2022/06/06 17:44:30 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	get_size_simple(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

int	get_size_double(int size, char **strs)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += get_size_simple(*(strs + i));
		i++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(dest + i) != '\0')
		i++;
	while (*(src + j) != '\0')
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		len_strs;
	int		len_sep;
	int		i;

	if (size == 0)
	{
		str = NULL;
		return (str);
	}
	len_strs = get_size_double(size, strs);
	len_sep = get_size_simple(sep);
	str = malloc(len_strs * sizeof(char) + (size) * len_sep + 1);
	i = 0;
	while (i < size)
	{
		str = ft_strcat(str, strs[i]);
		if (i != size - 1)
			str = ft_strcat(str, sep);
		i++;
	}
	return (str);
}
