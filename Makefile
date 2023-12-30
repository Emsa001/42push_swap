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
BONUS_NAME = checker

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source Files
SRC_DIR = src
SRC_DIR_BONUS = bonus
INCLUDES_DIR = includes

SRC = $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)
SRC_BONUS = $(wildcard $(SRC_DIR_BONUS)/**/*.c) $(wildcard $(SRC_DIR_BONUS)/*.c)

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

fclean: clean
	$(LIBFT_MAKE) fclean
	rm -f $(NAME)

re: fclean all

bonus: $(LIBFT) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(BONUS_NAME)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

t: 
	make
	clear
	./$(NAME) 5 2 7 1 6 3 9 4 8
	
.PHONY: all clean fclean re bonus t