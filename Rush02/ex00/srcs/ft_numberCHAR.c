/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberCHAR.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbugnico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:05:22 by jbugnico          #+#    #+#             */
/*   Updated: 2022/03/06 20:34:51 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_h.h"

char	*ft_remp_tmp(char *tmp, char *str, int len, int *i);
char	*ft_div_char(char *cle);

void	ft_algo_aff1(int *tab, char *cle, t_data *datas)
{
	char	*h;

	h = "0";
	while (ft_strcmp(datas[tab[1]].key, "-1")
		&& ft_strcmp(ft_str_power(h, 3), cle) != 0
		&& ft_strcmp(ft_str_power(h, 2), cle) != 0 && ft_strcmp(h, cle) != 0)
	{
		h = ft_str_power("10", ft_strlen(datas[tab[1]].key));
		tab[1]++;
	}
	ft_putstr(datas[tab[1]].value);
}

void	ft_algo(int *tab, char **chta, char *str, t_data *datas)
{
	char	*h;

	h = "0";
	while (tab[0] + 2 < ft_strlen(str))
	{
		tab[1] = 0;
		chta[0] = ft_remp_tmp(chta[0], str, tab[2], &tab[0]);
		ft_hundreds(chta[0], datas);
		if (ft_strlen(chta[1]) > 4 && ft_strcmp(chta[0], "000") != 0)
		{	
			ft_algo_aff1(tab, chta[1], datas);
		}
		if (ft_strcmp(chta[1], "1000") == 0 && ft_strcmp(chta[0], "000") != 0)
		{
			while (ft_strcmp(datas[tab[1]].key, "-1")
				&& ft_strcmp(h, chta[1]) != 0)
			{
				h = ft_str_power("10", ft_strlen(datas[tab[1]].key));
				tab[1]++;
			}
			ft_putstr(datas[tab[1]].value);
		}
		chta[1] = ft_div_char(chta[1]);
		tab[2] = tab[2] - tab[2] % 3;
	}
}

int	ft_number(char *str, t_data *datas)
{
	int		tab[3];
	char	**chta;

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = ft_strlen(str);
	chta = malloc(sizeof(char *) * 2);
	chta[0] = malloc(sizeof(char) * 3);
	chta[1] = ft_long(ft_strlen(str));
	ft_algo(tab, chta, str, datas);
	free(chta[0]);
	return (0);
}
