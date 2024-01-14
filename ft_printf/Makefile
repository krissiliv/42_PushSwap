RM := rm -rf

NAME := ft_printf.a

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

CC = cc
COMPILER_FLAGS = -Wall -Wextra -Werror
HEADERS = -I .
COMPILE = $(CC) $(COMPILER_FLAGS) $(HEADERS)

SRCS = ft_printf.c ft_printf_d_int.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(COMPILE) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)