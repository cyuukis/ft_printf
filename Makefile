NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Werror -Wextra -c
HEADER = ft_printf.h
FUNCS = ft_printf.c
OBJS = $(FUNCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(FUNCS) ft_printf.h
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY:	clean	fclean	all	re