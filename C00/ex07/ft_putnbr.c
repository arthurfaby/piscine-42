/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:58:48 by afaby             #+#    #+#             */
/*   Updated: 2022/02/18 09:48:53 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	power(int n, int p)
{
	int	res;

	res = 1;
	while (p > 0)
	{
		res *= n;
		p--;
	}
	return (res);
}

int	get_size(int n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

int	get_largest(int n)
{
	int	largest;

	largest = 0;
	while (n > 0)
	{
		largest = n % 10;
		n /= 10;
	}
	return (largest);
}

void	ft_putnbr(int nb)
{
	int	largest;
	int	size;

	if (nb == 0)
	{
		ft_putchar('0');
	}
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	size = get_size(nb);
	while (nb > 0)
	{	
		largest = get_largest(nb);
		ft_putchar(largest + '0');
		nb = nb - largest * (power(10, size - 1));
		size--;
	}
}
