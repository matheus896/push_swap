NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRCS = src/stack.c src/ops_swap_push.c src/ops_rotate.c src/sort_3.c \
       src/main.c src/parse.c src/strategy.c src/dispatch.c \
       src/ops_rev_rotate.c src/sort_simple.c src/bench_count.c \
       src/bench.c src/chunk_helpers.c src/chunk_sort.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
LIBS = -Llibft -lft -Lft_printf -lftprintf

all: $(NAME)

$(LIBFT):
	make -C libft

$(FT_PRINTF):
	make -C ft_printf

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
