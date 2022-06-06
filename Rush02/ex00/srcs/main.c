/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:31:45 by afaby             #+#    #+#             */
/*   Updated: 2022/06/06 17:58:42 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_h.h"

int		ft_check_params(char *str);
int		check_zero(char *str, t_data *datas);
char	*add_zeros(char *str);

int	errors(int argc, char **argv)
{
	if (argc == 2 && ft_check_params(argv[1]) == 1)
		return (ft_print_error());
	if (argc == 3 && ft_check_params(argv[2]) == 1)
		return (ft_print_error());
	if ((argc < 2 || argc > 3))
		return (ft_print_error());
	return (0);
}

int	dict_errors(char *arg, t_data *datas)
{
	if (datas == NULL)
		return (ft_print_dict_error());
	if (check_zero(arg, datas))
		return (0);
	ft_number(arg, datas);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*path;
	t_data	*datas;
	char	*arg;
	char	*param;

	path = "numbers.dict";
	if (errors(argc, argv) == 1)
		return (0);
	if (argc == 3)
	{
		param = argv[2];
		path = argv[1];
	}
	else
		param = argv[1];
	if (ft_strlen(param) < 3)
		arg = add_zeros(param);
	else
		arg = param;
	if (ft_check_dico(path) == 1)
		return (0);
	datas = ft_parse(path);
	return (dict_errors(arg, datas));
}
