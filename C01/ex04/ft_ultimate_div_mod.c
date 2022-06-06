/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:32:19 by afaby             #+#    #+#             */
/*   Updated: 2022/02/21 16:52:45 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int*b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

int	main(void)
{
	int	*a;
	int	*b;
	int	x;
	int	y;

	x = 42;
	y = 5;
	a = &x;
	b = &y;
	ft_ultimate_div_mod(a, b);
	printf("%d %d\n%d %d", *a, *b, x, y);
}
