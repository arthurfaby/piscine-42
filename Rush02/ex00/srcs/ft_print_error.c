/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:01:27 by cbourre           #+#    #+#             */
/*   Updated: 2022/03/06 14:12:12 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_h.h"

int	ft_print_dict_error(void)
{
	write(1, "Dict Error\n", 11);
	return (1);
}

int	ft_print_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}
