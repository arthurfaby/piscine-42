/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:39:00 by afaby             #+#    #+#             */
/*   Updated: 2022/03/03 10:43:33 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

int	is_in_base(char c, char *base)
{
	while (*base)
	{
		if (c == *base)
			return (1);
		base++;
	}
	return (0);
}

int	ft_charpos(char c, char *str)
{
	int	pos;

	pos = 0;
	while (*str)
	{
		if (*str == c)
		{
			return (pos);
		}
		pos++;
		str++;
	}
	return (-1);
}

int	check_base_validity(char *str)
{
	int		i;
	int		j;
	char	c;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (*(str + i))
	{
		c = *(str + i);
		if (c == '-' || c == '+' || c == ' ' || (c >= 9 && c <= 13))
			return (0);
		j = 1;
		while (*(str + i + j))
		{
			if (*(str + i) == *(str + i + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
