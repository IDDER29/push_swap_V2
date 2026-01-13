# Library name
LIB_NAME    = libftprintf.a

# Executable name (required by subject as NAME)
NAME        = push_swap
EXEC_NAME   = $(NAME)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Library sources (ft_printf)
LIB_SRCS    = ft_printf.c ft_printf_utils.c ft_print_str.c ft_strlen.c
LIB_OBJS    = $(LIB_SRCS:.c=.o)

# Push swap sources
PUSH_SRCS   = main.c \
              input_validation.c \
              input_parse_utils.c \
              input_parse_string.c \
              input_parse_args.c \
              push_swap_main.c \
              stack_operations.c \
              stack_push_operations.c \
              swap_operations.c \
              rotate_operations.c \
              reverse_rotate_operations.c \
              algorithm_sort.c \
              algorithm_target.c \
              algorithm_cost.c \
              algorithm_execute.c \
              utilities.c \
              stack_output.c

PUSH_OBJS   = $(PUSH_SRCS:.c=.o)

HEADERS     = ft_printf.h push_swap.h

AR          = ar rcs
RM          = rm -f

.PHONY: all clean fclean re

all: $(LIB_NAME) $(EXEC_NAME)

# Build the library
$(LIB_NAME): $(LIB_OBJS)
	$(AR) $(LIB_NAME) $(LIB_OBJS)

# Build the executable
$(EXEC_NAME): $(LIB_NAME) $(PUSH_OBJS)
	$(CC) $(CFLAGS) $(PUSH_OBJS) $(LIB_NAME) -o $(EXEC_NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(LIB_OBJS) $(PUSH_OBJS)

fclean: clean
	$(RM) $(LIB_NAME) $(EXEC_NAME)

re: fclean all