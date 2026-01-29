NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SRCS =	swap_and_push.c \
	rots_a_b.c \
	rotrevs_a_b.c \
	sort_stack.c \
	push_swap.c \
	push_swap_utils.c \
	turk.c \
	turk_utils.c \

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(FLAGS) $(OBJ) -L $(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) -I $(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

beautiful: re
	make clean
	clear
