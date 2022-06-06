/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:51:38 by afaby             #+#    #+#             */
/*   Updated: 2022/02/22 16:57:44 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ascii(int n)
{
	return (n + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_nb(int a, int b)
{
	int	a1;
	int	a2;
	int	b1;
	int	b2;

	a1 = a / 10;
	a2 = a % 10;
	b1 = b / 10;
	b2 = b % 10;
	ft_putchar(ascii(a1));
	ft_putchar(ascii(a2));
	write(1, " ", 1);
	ft_putchar(ascii(b1));
	ft_putchar(ascii(b2));
	if (a != 98)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 99)
	{
		while (b <= 99)
		{
			ft_print_nb(a, b);
			b++;
		}
		b = a + 2;
		a++;
	}
}

int	main(void)
{
	ft_print_comb2();
}
