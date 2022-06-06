/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 09:03:20 by afaby             #+#    #+#             */
/*   Updated: 2022/03/10 09:31:34 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "h.h"

int	main(void)
{
	int	a;
	int	b;
	int	*pa;
	int	*pb;

	a = 10;
	b = 5;
	pa = &a;
	pb = &b;
	ft_putchar('K');
	ft_putstr("\nhello world\n");
	printf("len de 'lolilol' : %d\n", ft_strlen("lolilol"));
	ft_swap(pa, pb);
	printf("%d | %d\n", *pa, *pb);
	printf("cmp : %d\n", ft_strcmp("hello world", "hello worlda"));
}
