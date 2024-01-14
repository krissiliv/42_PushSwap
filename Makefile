RM := rm -rf

NAME := push_swap
FT_PRINTFNAME := ./ft_printf/ft_printf.a

.PHONY: all clean fclean re ft_printf

all: $(NAME)

clean:
	cd ft_printf && $(MAKE) clean
	$(RM) $(OBJS)

fclean: clean
	cd ft_printf && $(MAKE) fclean
	$(RM) $(NAME)

re: fclean all 

CFLAGS = -Wall -Wextra -Werror
HEADERS = -I .

SRCS = push_swap.c check_input.c collective_operations.c create_print_stack.c effective_operations.c elementary_operations.c ft_atoi.c ft_split.c my_first_algorithm.c my_second_algorithm.c my_second_algorithm_utils.c search_operations.c small_list_algorithm.c whole_list_checks.c
OBJS = $(SRCS:.c=.o)

$(FT_PRINTFNAME):
	cd ft_printf && $(MAKE) all

${NAME}: ${OBJS}
	@${MAKE} -C ./ft_printf --no-print-directory
	@${CC} ${CFLAGS} ${OBJS} ./ft_printf/ft_printf.a -o ${NAME}