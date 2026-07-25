NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRC_DIR		= src
OBJ_DIR		= obj
SRC			= $(SRC_DIR)/ft_printf.c $(SRC_DIR)/utils.c $(SRC_DIR)/handlers.c
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ft_printf.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
