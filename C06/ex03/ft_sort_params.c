/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:18:24 by afaby             #+#    #+#             */
/*   Updated: 2022/02/25 10:18:13 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

int	ft_strcmp(char	*s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) != '\0' && *(s2 + i) != '\0')
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (*(s1 + i) - *(s2 + i));
}

void	sort_params(char **argv)
{
	int		i;
	int		size;
	char	*tmp;

	i = 1;
	size = 0;
	while (*(argv + size))
		size++;
	while (*(argv + i) && i < (size - 1))
	{
		if (ft_strcmp(*(argv + i), *(argv + i + 1)) > 0)
		{
			tmp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = tmp;
			i = 1;
		}
		else
			i++;
	}
}

int	main(int argc, char **argv)
{
	char	*argv0;

	(void)argc;
	argv0 = argv[0];
	sort_params(argv);
	while (*argv)
	{
		if (*argv != argv0)
			ft_putstr(*argv);
		argv++;
	}
	return (0);
}
