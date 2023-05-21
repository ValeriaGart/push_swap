LIBFT = ./libft/libft.a

NAME = push_swap

SRCS =	src/push_swap.c					\
		src/check_input.c				\
		src/free.c						\
		src/sort1.c						\
		src/utils.c						\
		src/short_sort.c				\
		src/split_blah_blahs.c			\
		src/secret_scheme_behind.c

CC = cc

CFLAGS = -g -Wextra -Werror -Wall

INCL = -I ./incl

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT)

all:    $(NAME)

clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
