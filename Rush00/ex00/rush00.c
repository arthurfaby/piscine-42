/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:04:27 by rledoux           #+#    #+#             */
/*   Updated: 2022/02/19 15:56:33 by pirabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_botop(int x)
{
	int	b;

	b = 1;
	while (b <= x)
	{
		if (b == 1 || b == x)
			ft_putchar('o');
		else
			ft_putchar('-');
		++b;
	}
}

void	ft_print_mid(int x)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if (i == 1 || i == x)
			ft_putchar('|');
		else
			ft_putchar(' ');
		i++;
	}
}

int	checkerror(int x, int y)
{
	char	*err;
	int		i;

	err = "Doucement Doc... Des chiffres entre 1 et 2 147 483 647,please ;)\n";
	i = 0;
	if (x <= 0 || y <= 0)
	{
		while (err[i])
		{
			ft_putchar(err[i]);
			i++;
		}
		return (1);
	}
	else
		return (0);
}

int	rush(int x, int y)
{
	int	r;

	r = 1;
	if (checkerror(x, y) == 1)
		return (1);
	else
	{
		while (r <= y)
		{
			if (r == 1 || r == y)
			{
				ft_print_botop(x);
				ft_putchar('\n');
			}
			else
			{
				ft_print_mid(x);
				ft_putchar('\n');
			}
			++r;
		}
		return (0);
	}
}
