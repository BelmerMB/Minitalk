NAME =		client
HEADER =	./includes
SRC_DIR =	./src
OBJ_DIR =	./objects
LIBFT_DIR =	./printf
LIBFT =		$(addprefix $(LIBFT_DIR)/, libftprintf.a)

SRC_FILES =	client.c 

FLAGS_ERROR =	-Wall -Wextra -Werror
SRC =			$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ =			$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
CFLAGS =		-g3 -O3

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cc $(OBJ) $(LIBFT) $(CFLAGS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	cc $(FLAGS_ERROR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
