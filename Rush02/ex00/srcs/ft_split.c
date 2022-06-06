/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:48:00 by afaby             #+#    #+#             */
/*   Updated: 2022/03/06 14:57:49 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_h.h"

int	is_in_set(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int		start;
	int		end;
	int		i;
	int		n;

	start = 0;
	end = 0;
	i = 0;
	n = 0;
	while (*(str + i))
	{
		if (is_in_set(*(str + i), charset))
		{
			end = i;
			if ((start != end))
				n++;
			start = end + 1;
		}
		i++;
	}
	return (n);
}

char	*isolation(int start, int end, char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * (end - start) + 1);
	while (start < end)
	{
		*(tmp + i) = *(str + start);
		start++;
		i++;
	}
	*(tmp + i) = '\0';
	return (tmp);
}

char	**ft_split(char *str, char *charset)
{
	char	**list;
	int		start;
	int		end;
	int		i;
	int		n;

	start = 0;
	end = 0;
	i = -1;
	n = 0;
	list = malloc(sizeof(char *) * count_words(str, charset) + 1);
	while (*(str + ++i))
	{
		if (is_in_set(*(str + i), charset))
		{
			end = i;
			if ((start != end))
				*(list + n++) = isolation(start, end, str);
			start = end + 1;
		}
	}
	if (start != ft_strlen(str))
		*(list + n++) = isolation(start, ft_strlen(str), str);
	*(list + n) = 0;
	return (list);
}
