GREEN=\033[32m


OBJ = $(SRC:.c=.o)
LIBFT_DIR = LIBFT
LIBFT = $(LIBFT_DIR)/libft.a
GCC_FLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
RM = rm -f

SRC_DIR = SRC
SRC = $(SRC_DIR)/ft_free.c $(SRC_DIR)/pushswap.c $(SRC_DIR)/ft_lstlast.c $(SRC_DIR)/ft_lstprint.c $(SRC_DIR)/ft_creatnewnode.c $(SRC_DIR)/ft_utilis.c $(SRC_DIR)/ft_creatlst.c $(SRC_DIR)/ft_instructions.c $(SRC_DIR)/push_to.c $(SRC_DIR)/ft_lstsize.c $(SRC_DIR)/convert_to_array.c $(SRC_DIR)/small.c
MAIN = $(SRC_DIR)/main.c
HEADER = $(SRC_DIR)/pushswap.h

all : $(NAME)

$(NAME) : $(OBJ) $(MAIN) $(HEADER) $(LIBFT)
	@$(CC) $(GCC_FLAGS) $(MAIN) $(OBJ)  $(LIBFT) -o $(NAME)
	@echo""
	@sleep 0.2
	@echo "     $(GREEN)Compiling..........$(GREEN)"
	@sleep 0.2
	@echo ""
$(LIBFT) : $(shell find $(LIBFT_DIR) -name "*.c" -type f)
	@$(MAKE) -C $(LIBFT_DIR)/

%.o: %.c
	@$(CC) $(GCC_FLAGS) -c $^ -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR)/ clean
	@rm -f $(OBJ)
fclean           : 
	@$(MAKE) -C $(LIBFT_DIR)/ fclean
	@rm -f $(OBJ) $(NAME)
re : fclean all
	