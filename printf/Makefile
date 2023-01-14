NAME		= libftprintf.a

SRCS		= ./src/ft_printf.c ./src/ft_printf_utils.c ./src/ft_convert_hex.c ./src/ft_ptr_to_hex.c

HEADER		= ft_printf.h 

OBJS		= ${SRCS:.c=.o}

CFLAGS		= -Wall -Wextra -Werror

all: ${NAME}

.c.o: ${HEADER} Makefile
	cc ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	make -C ./libft
	mv ./libft/libft.a ./${NAME}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}
	make clean -C ./libft

fclean:
	rm -f ${OBJS}
	rm -f ${NAME}
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re