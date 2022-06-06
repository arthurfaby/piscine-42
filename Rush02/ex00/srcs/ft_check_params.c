/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:30:09 by cbourre           #+#    #+#             */
/*   Updated: 2022/03/06 17:31:31 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_h.h"

// verifie si caractere alpha ou autre dans str
int	ft_check_params(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

// affiche les erreurs
/*int	ft_check_error(int argc, char **argv)
{
	if (ft_check_params(argv[1]) == 1 || (argc < 2 || argc > 3))
		ft_print_error();
	return (0);
}*/
