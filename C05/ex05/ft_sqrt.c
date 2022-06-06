/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:29:15 by afaby             #+#    #+#             */
/*   Updated: 2022/02/28 18:11:18 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	res;

	res = 0;
	while (res <= 46340)
	{
		if ((res * res) == nb)
			return (res);
		res++;
	}
	return (0);
}