NAME = libftprintf.a

SRC_DIR = src
INC_DIR = src
UTILS_DIR = utils
LIBFT_DIR = 42_libft

SRC = ft_printf.c print_int.c print_char.c print_str.c print_ptr.c
UTILS = ft_itoa_base.c
OBJ = $(SRC:%.c=$(SRC_DIR)/%.o) $(UTILS:%.c=$(UTILS_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
