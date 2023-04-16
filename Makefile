LIBFT = ./libft/libft.a

NAME = push_swap

SRCS =	src/push_swap.c					\
		src/check_input.c				\
		src/free.c						\
		src/recursive_sort.c			\
		src/secret_scheme_behind.c		\
		src/sort_prepare.c   			\
		src/utils.c

CC = cc

CFLAGS = -g -Wextra -Werror -Wall

INCL = -I ./incl

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT)

all:    $(NAME)

clean:
		$(MAKE) -C ./libft
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re