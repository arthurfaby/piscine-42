/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:32:34 by afaby             #+#    #+#             */
/*   Updated: 2022/02/20 15:27:56 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_char_is_numeric(char c)
{
	if (!((48 <= c && c <= 57)))
	{
		return (0);
	}
	return (1);
}

int	ft_char_is_alpha(char c)
{
	if (!((65 <= c && c <= 90)
			|| (97 <= c && c <= 122)))
	{
		return (0);
	}
	return (1);
}

int	ft_char_is_alphanumeric(char c)
{
	return (ft_char_is_alpha(c) || ft_char_is_numeric(c));
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	c;
	int		have_to_cpt;

	if (*str >= 'a' && *str <= 'z')
		have_to_cpt = 1;
	i = 0;
	while (*(str + i) != '\0')
	{
		c = *(str + i);
		if (have_to_cpt && c >= 'a' && c <= 'z')
			str[i] -= 32;
		else if (!have_to_cpt && c >= 'A' && c <= 'Z')
			str[i] += 32;
		if (!ft_char_is_alphanumeric(c))
			have_to_cpt = 1;
		else
			have_to_cpt = 0;
		i++;
	}
	return (str);
}
