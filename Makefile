NAME = push_swap
CC = cc 
FLAG = -Wall -Wextra -Werror -g3
LIBFT_PATH = ./libft/
LIBFT = libft.a
LIBFT_LIB = $(addprefix $(LIBFT_PATH), $(LIBFT))
SRC_DIR = ./src/
INC_DIR = ./include/
PARSING = $(addprefix parsing/, parsing.c parsing_utils.c)
SORT = $(addprefix sort/, sort.c simple_sort.c simple_sort_utils.c)
INSTRUCT = $(addprefix instruct/, instructions.c list_utils.c)
SRC = $(addprefix $(SRC_DIR), $(PARSING) $(SORT) $(INSTRUCT) push_swap.c normalize.c)
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
