NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS			=	main.c \
					error.c \
					list.c \
					push.c \
					radix_sort.c \
					reverse_rotate.c \
					rotate.c \
					s_sort.c \
					stack.c \
					swap.c \
					libft_ps.c \
					ft_split.c \
					s_sort_case.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
