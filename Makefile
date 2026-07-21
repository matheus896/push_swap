NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = stack.c ops_swap_push.c ops_rotate.c sort_3.c main.c parse.c \
       strategy.c dispatch.c ops_rev_rotate.c sort_simple.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all