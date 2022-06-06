# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 17:22:48 by afaby             #+#    #+#              #
#    Updated: 2022/03/06 20:31:31 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		srcs/main.c \
			srcs/ft_print_error.c \
			srcs/ft_check_dico.c \
			srcs/ft_check_params.c \
			srcs/ft_dict.c \
			srcs/ft_hundreds2MODIF.c \
			srcs/ft_numberCHAR.c \
			srcs/ft_number_op.c \
			srcs/ft_split.c \
			srcs/ft_str.c \
			srcs/ft_str_power.c \
			srcs/ft_particular_cases.c

HEADERS =	includes/ft_h.h

NAME =		rush-02

CC =		gcc

RM =		rm -f

CFLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(HEADERS) $(SRCS)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
