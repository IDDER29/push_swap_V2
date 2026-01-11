NAME    = libftprintf.a

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ft_printf.c ft_printf_utils.c ft_print_str.c ft_strlen.c
OBJS    = $(SRCS:.c=.o)

HEAD    = ft_printf.h

AR      = ar rcs
RM      = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all