/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:27:20 by afaby             #+#    #+#             */
/*   Updated: 2022/03/06 20:20:01 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 8192

typedef struct s_data
{
	char	*key;
	char	*value;
}	t_data;

char	*ft_long(int len);
char	*ft_div_char(char *cle);
char	*ft_remp_tmp(char *tmp, char *str, int len, int *i);
int		ft_print_error(void);
int		ft_check_params(char *str);
int		ft_print_dict_error(void);
int		ft_strlen(char *str);
int		ft_check_line(char *str);
int		ft_check_dico(char *path);
t_data	*create_data(char *str);
int		count_line(int fd);
void	ft_print_datas(t_data *datas);
t_data	*ft_parse(char *path);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_hundreds(char *str, t_data *datas);
int		ft_str_is_numeric(char *str);
int		ft_recursive_power(int nb, int power);
char	*ft_long(int len);
int		ft_number(char *str, t_data *datas);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *src);
int		is_in_set(char c, char *charset);
int		count_words(char *str, char *charset);
char	*ft_str_power(char *str, int power);
char	*isolation(int start, int end, char *str);
char	**ft_split(char *str, char *charset);
void	ft_algo_aff1(int *tab, char *cle, t_data *datas);
void	ft_algo(int *tab, char **chta, char *str, t_data *datas);
int		ft_number(char *str, t_data *datas);
int		count_lines(int fd);
char	*add_zeros(char *str);
int		check_zero(char *str, t_data *datas);

#endif
