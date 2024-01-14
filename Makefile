# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 13:49:31 by escura            #+#    #+#              #
#    Updated: 2023/12/18 22:57:56 by escura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source Files
SRC_DIR = src
SRC_DIR_BONUS = bonus
INCLUDES_DIR = includes

SRC = $(SRC_DIR)/push_swap.c $(SRC_DIR)/utils/general.c $(SRC_DIR)/utils/read_args.c $(SRC_DIR)/utils/read_utils.c \
	$(SRC_DIR)/utils/sort_utils.c $(SRC_DIR)/sorter/sort_large.c $(SRC_DIR)/sorter/sort_tiny.c \
	$(SRC_DIR)/sorter/sort.c $(SRC_DIR)/sorter/new/new_elem.c $(SRC_DIR)/sorter/new/new_max_min_a.c \
	$(SRC_DIR)/sorter/new/new_max_min_b.c $(SRC_DIR)/sorter/moves/check_moves.c $(SRC_DIR)/sorter/moves/max_min.c \
	$(SRC_DIR)/sorter/moves/move_back.c $(SRC_DIR)/operators/push.c $(SRC_DIR)/operators/reverse_rotate.c \
	$(SRC_DIR)/operators/rotate.c $(SRC_DIR)/operators/swap.c
	
SRC_BONUS = $(SRC_DIR_BONUS)/main.c $(SRC_DIR_BONUS)/utils/ft_utils.c $(SRC_DIR_BONUS)/utils/general.c \
			$(SRC_DIR_BONUS)/utils/read_args.c $(SRC_DIR_BONUS)/utils/read_utils.c $(SRC_DIR_BONUS)/operators/push.c \
			$(SRC_DIR_BONUS)/operators/reverse_rotate.c $(SRC_DIR_BONUS)/operators/rotate.c \
			$(SRC_DIR_BONUS)/operators/swap.c $(SRC_DIR_BONUS)/checker/execute.c $(SRC_DIR_BONUS)/checker/read.c

OBJ_DIR = obj
OBJ_DIR_BONUS = obj_bonus
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_BONUS = $(patsubst $(SRC_DIR_BONUS)/%.c, $(OBJ_DIR_BONUS)/%.o, $(SRC_BONUS))

# Libft
LIBFT_DIR = $(INCLUDES_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(LIBFT_MAKE)

clean:
	$(LIBFT_MAKE) clean
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_DIR_BONUS)

fclean: clean
	$(LIBFT_MAKE) fclean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

bonus: $(LIBFT) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	
.PHONY: all clean fclean re bonus