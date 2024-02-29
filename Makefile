NAME = push_swap
CC = cc 
FLAG = -Wall -Wextra -Werror -g3
LIBFT_PATH = ./libft/
LIBFT = libft.a
LIBFT_LIB = $(addprefix $(LIBFT_PATH), $(LIBFT))
C_FILES = ./parsing/parsing.c ./parsing/parsing_utils.c push_swap.c ./sort/sort.c ./instruct/instructions.c ./instruct/list_utils.c ./sort/sort_functions_utils.c
SRC_DIR = ./src/
INC_DIR = ./include/
SRC = $(addprefix $(SRC_DIR), $(C_FILES))
OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): lib $(OBJ)
	$(CC) $(FLAG) $(OBJ) $(LIBFT_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(FLAG) -I$(INC_DIR) -c $< -o $@

lib:
	@make -C $(LIBFT_PATH)

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH) || true

re: fclean all

.PHONY: all clean fclean re
