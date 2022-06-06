/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main05.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:01:43 by afaby             #+#    #+#             */
/*   Updated: 2022/03/10 14:11:05 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int	main(int argc, char **argv)
{
	char	**list;
	int		i;

	i = 0;
	if (argc != 3)
		return (0);
	list = ft_split(argv[1], argv[2]);
	while (list[i] != 0)
	{
		printf("%s\n", list[i]);
		free(list[i]);
		i++;
	}	
	free(list);
}
