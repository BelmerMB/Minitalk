NAME =
CLIENT =	client
SERVER = 	server
HEADER =	./includes
SRC_DIR =	./src
OBJ_DIR =	./objects
LIBFT_DIR =	./printf
LIBFT =		$(addprefix $(LIBFT_DIR)/, libftprintf.a)
SRC_CLIENT =	client.c
SRC_SERVER =	server.c

FLAGS_ERROR =	-Wall -Wextra -Werror
SRC_S =			$(addprefix $(SRC_DIR)/, $(SRC_SERVER))
OBJ_S =			$(addprefix $(OBJ_DIR)/, $(SRC_SERVER:.c=.o))

SRC_C=			$(addprefix $(SRC_DIR)/, $(SRC_CLIENT))
OBJ_C =			$(addprefix $(OBJ_DIR)/, $(SRC_CLIENT:.c=.o))

CFLAGS =		-g3 -O3

all: $(SERVER) $(CLIENT)

$(CLIENT): $(OBJ_C) $(LIBFT)
	cc $(FLAGS_ERROR) $(OBJ_C) $(LIBFT) $(CFLAGS) -o $(CLIENT)

$(SERVER): $(OBJ_S) $(LIBFT)
	cc $(FLAGS_ERROR) $(OBJ_S) $(LIBFT) $(CFLAGS) -o $(SERVER)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	cc $(FLAGS_ERROR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(CLIENT)
	rm -f $(SERVER)
	@rm -f $(LIBFT)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
