gcc -Wextra -Werror -Wall -c ft_putchar.c ft_strcmp.c ft_strlen.c ft_swap.c ft_putstr.c
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
ranlib libft.a
rm -f ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
