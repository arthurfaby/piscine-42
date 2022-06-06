# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 09:58:48 by afaby             #+#    #+#              #
#    Updated: 2022/03/09 18:49:12 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bsq

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SDIR		=	srcs/

HDIR	=	includes/

SRCS	=	${addprefix $(SDIR),*.c}

HEADS	=	${addprefix $(HDIR),*.h}

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(HEADS) -g -fno-stack-protector
fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean all
