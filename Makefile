NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

FNC = check_error.c ft_atol.c ft_lst.c ft_split.c push.c reverse_rotate.c rotate.c swap.c assign_index.c small_sort.c radix_sort.c main.c

OBJS = ${FNC:.c=.o}

all: ${NAME}

${NAME} : ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re