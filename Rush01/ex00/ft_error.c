/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:56:49 by vnaud             #+#    #+#             */
/*   Updated: 2022/02/27 16:02:47 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

void	ft_print_error(void)
{
	write(1, "Error\n", 6);
}

int	ft_check_size_error(char *str)
{
	int	size;

	size = 0;
	while (*(str + size))
		size++;
	if (size > 71 || size < 23)
	{
		printf("on sort la");
		return (0);
	}
	if (size % 2 == 0)
	{
		printf("cest ici en fait");
		return (0);
	}
	if ((((size + 1) / 2) % 4) != 0)
		return (0);
	return (1);
}

int	ft_check_char_error(char *str)
{
	int	count_one;
	int	count_limit_max;
	int	index;
	int	size_params;

	size_params = (ft_str_len(str) + 1) / 2 / 4;
	index = -1;
	count_one = 0;
	count_limit_max = 0;
	while (str[++index])
	{
		if (str[index] == (size_params + '0'))
			count_limit_max++;
		if (str[index] == '1')
			count_one++;
		if (count_limit_max > size_params || count_one > size_params)
			return (0);
	}
	return (1);
}

int	ft_check_pattern_error(char *str)
{
	int	index;
	int	size_params;

	size_params = (ft_str_len(str) + 1) / 2 / 4;
	index = -1;
	while (str[++index])
	{
		if (index % 2 == 0 && (str[index] < '0'
				|| str[index] > size_params + '0'))
			return (0);
		else if (index % 2 != 0 && str[index] != ' ')
			return (0);
	}
	return (1);
}

int	ft_check_error(char *str)
{
	if (!ft_check_size_error(str))
		return (0);
	if (!ft_check_pattern_error(str))
		return (0);
	if (!ft_check_char_error(str))
		return (0);
	return (1);
}
