SRC = main.c

LIBFTDIR = include/libftfin/

LIBFT = include/libftfin/libft.a

CC = gcc

NAME = push_swap

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(SRC) -L$(LIBFTDIR) -lft -o $(NAME)

$(LIBFT):
		$(MAKE) -C $(LIBFTDIR)

all:		${NAME}

re: fclean all
clean :
	$(MAKE) -C $(LIBFTDIR) fclean
fclean: clean
		rm -rf $(NAME)