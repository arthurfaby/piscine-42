/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:04:50 by afaby             #+#    #+#             */
/*   Updated: 2022/03/04 11:01:50 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str);
int	is_in_base(char c, char *base);
int	ft_charpos(char c, char *str);
int	check_base_validity(char *str);

void	ft_putnbr_base(long int nbr, char *base, char *res, int *pos)
{
	int		base_len;

	if (check_base_validity(base))
	{
		base_len = ft_strlen(base);
		if (nbr == -2147483648)
		{
			ft_putnbr_base(nbr / base_len, base, res, pos);
			*(res + (*pos)++) = base[nbr % base_len];
			return ;
		}
		if (nbr < 0)
		{
			*(res + (*pos)++) = '-';
			nbr *= -1;
		}
		if (nbr < base_len)
			*(res + (*pos)++) = base[nbr];
		else
		{
			ft_putnbr_base(nbr / base_len, base, res, pos);
			ft_putnbr_base(nbr % base_len, base, res, pos);
		}
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	value;
	int	is_neg;
	int	bl;

	is_neg = 1;
	if (!check_base_validity(base))
		return (0);
	value = 0;
	bl = ft_strlen(base);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_neg *= -1;
		str++;
	}
	while (*str && is_in_base(*str, base))
	{
		value = (value * bl) + ft_charpos(*str, base);
		str++;
	}
	return (is_neg * value);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec;
	char	tmp[40];
	int		pos;
	char	*res;

	pos = 0;
	dec = ft_atoi_base(nbr, base_from);
	ft_putnbr_base(dec, base_to, tmp, &pos);
	*(tmp + pos) = '\0';
	res = malloc(sizeof(char) * ft_strlen(tmp) + 1);
	res = tmp;
	return (res);
}
