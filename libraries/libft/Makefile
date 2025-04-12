# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 20:21:32 by brturcio          #+#    #+#              #
#    Updated: 2025/04/11 20:31:59 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------ VARIABLES PRINCIPALES ------------------

NAME		:= mylib42.a
INCDIR		:= inc
OBJDIR		:= obj

# Carpetas de módulos
SRCDIRS		:= libft ft_printf get_next_line

# Archivos fuente (busca todos los .c en los subdirectorios)
SRC			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
OBJ			:= $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

# Compilador y flags
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -I$(INCDIR)

# ------------------ REGLAS ------------------

all: $(NAME)

# Compilar librería
$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo "✅ Librería creada: $(NAME)"

# Compilación de cada archivo .c en su .o en la carpeta obj/
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpiar objetos
clean:
	@rm -rf $(OBJDIR)
	@echo "🧹 Carpeta obj/ eliminada."

# Limpiar objetos y la librería
fclean: clean
	@rm -f $(NAME)
	@echo "🧽 $(NAME) eliminado."

# Recomponer todo
re: fclean all

.PHONY: all clean fclean re
