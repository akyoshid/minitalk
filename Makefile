NAME = 			minitalk

# Program name
CLIENT_NAME =	client
SERVER_NAME =	server

# Directories
INC_DIR =		inc/
SRC_DIR =		src/
OBJ_DIR =		obj/
LIBFT_DIR =		libft/

# Header files
INC =			$(INC_DIR)minitalk.h

# Source files
CLIENT_SRC =	$(SRC_DIR)client.c
SERVER_SRC =	$(SRC_DIR)server.c

# Generate the list of object files in OBJ_DIR from source files in SRC_DIR
CLIENT_OBJ =	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(CLIENT_SRC))
SERVER_OBJ =	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SERVER_SRC))

# Compile
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_LIB = -L ./libft -lft

# Commands
RM = rm -f
AR = ar rcs

# Build rules
all: $(NAME)

bonus: $(NAME)

$(NAME): $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ -I$(INC_DIR) -o $@ $(LIBFT_LIB)

$(SERVER_NAME): $(SERVER_OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ -I$(INC_DIR) -o $@ $(LIBFT_LIB)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus