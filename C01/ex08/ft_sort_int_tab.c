/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:20:40 by afaby             #+#    #+#             */
/*   Updated: 2022/02/18 10:35:08 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (*(tab + i) > *(tab + i + 1))
		{
			ft_swap((tab + i), (tab + i + 1));
			i = 0;
		}
		else
		{
			i++;
		}
	}
}
