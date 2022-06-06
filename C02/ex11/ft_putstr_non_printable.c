/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:59:34 by afaby             #+#    #+#             */
/*   Updated: 2022/02/21 16:23:08 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hexadecimal(char c)
{
	char	*b;

	b = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(b[c / 16]);
	ft_putchar(b[c % 16]);
}

int	ft_char_is_printable(char c)
{
	if (!((32 <= c && c <= 126)))
	{
		return (0);
	}
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		if (!ft_char_is_printable(*tmp))
			ft_print_hexadecimal(*tmp);
		else
			ft_putchar(*tmp);
		tmp++;
	}
}
