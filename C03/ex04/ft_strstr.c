/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:08:11 by afaby             #+#    #+#             */
/*   Updated: 2022/02/25 17:01:06 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		j;
	int		i;
	char	*tmp;

	tmp = str;
	i = 0;
	if (*to_find == '\0')
		return (tmp);
	while (*(tmp + i) != '\0')
	{
		j = 0;
		while (*(str + i + j) != '\0' && *(str + i + j) == *(to_find + j))
		{
			if (*(to_find + j + 1) == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
