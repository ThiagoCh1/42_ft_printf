NAME = libftprintf.a

SRC_DIR   = src
INC_DIR   = src
UTILS_DIR = utils
LIBFT_DIR = 42_libft

SRC = ft_printf.c print_int.c print_char.c print_str.c print_ptr.c print_unint.c \
      print_hex.c print_percent.c

BONUS = parse_format.c

UTILS = ft_itoa_base.c apply_precision.c apply_width.c strjoin_free.c

OBJ        = $(SRC:%.c=$(SRC_DIR)/%.o) $(UTILS:%.c=$(UTILS_DIR)/%.o)
BONUS_OBJ  = $(BONUS:%.c=$(SRC_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0 -I $(INC_DIR) -I $(LIBFT_DIR)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ) $(BONUS_OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

bonus: all

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.c $(INC_DIR)/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
