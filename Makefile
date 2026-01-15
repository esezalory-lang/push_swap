NAME = push_swap
SRC = 	push_swap.c \
		error_handling.c \
		moves_a.c \
		moves_b.c \
		list_utils.c \
		utils.c \
		mini_sort.c \
		radix_sort.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re