/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:16:39 by afaby             #+#    #+#             */
/*   Updated: 2022/02/25 10:16:43 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

int	ft_arrlen(char **str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	int	len;
	int	i;

	(void)argc;
	i = 0;
	len = ft_arrlen(argv);
	while (i < len - 1)
	{
		ft_putstr(argv[len - 1 - i]);
		i++;
	}
	return (0);
}
