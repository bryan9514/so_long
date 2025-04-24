# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 15:57:57 by brturcio          #+#    #+#              #
#    Updated: 2025/04/24 08:22:39 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

SRC_DIR		:= src
OBJ_DIR		:= obj
SRC			:= $(wildcard $(SRC_DIR)/*.c)
OBJ			:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

LIBFT_DIR	:= libraries/libft
MLX42_DIR	:= libraries/MLX42

LIBFT		:= $(LIBFT_DIR)/libft.a
MLX42_LIB	:= $(MLX42_DIR)/build/libmlx42.a

INCLUDES	:= -I$(LIBFT_DIR)/inc -I$(MLX42_DIR)/include -Iinc

LIBS		:= $(LIBFT) $(MLX42_LIB)
MLX_FLAGS	:= -ldl -lglfw -lm -lX11 -pthread

all: $(LIBFT) $(MLX42_LIB) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(MLX_FLAGS) -o $@
	@echo "✅ Compilation completed: $(NAME)"

$(LIBFT):
	@if [ ! -f $@ ]; then \
		$(MAKE) -s -C $(LIBFT_DIR); \
	fi

$(MLX42_LIB):
	@if [ ! -f $@ ]; then \
		cmake -B $(MLX42_DIR)/build -S $(MLX42_DIR) > /dev/null 2>&1 && \
		$(MAKE) -s -C $(MLX42_DIR)/build -j4 > /dev/null 2>&1; \
		echo "✅ Library created : MLX42";\
	fi

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@rm -rf $(MLX42_DIR)/build
	@echo "✅ clean so_long done."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@echo "✅ fclean so_long done."

re: fclean all

.PHONY: all clean fclean re libft mlx
