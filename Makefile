NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = LIBFT
LIBFT_A = $(LIBFT_DIR)/libft.a

SRCS = push_swap.c \
		ft_strchry.c
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
