NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Werror -Wextra -c
HEADER = ft_printf.h
FUNCS = ft_printf.c ft_printf_utils.c add_s.c add_c.c add_x.c \
add_x_precision.c add_x_registr.c add_p.c add_p_registr.c add_u.c \
add_u_fs.c add_u_fl.c fl_u_fi.c add_di.c add_di_fl.c \
space_di_fisi.c add_di_space.c ft_itoa.c\

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
