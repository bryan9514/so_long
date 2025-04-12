# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 15:57:57 by brturcio          #+#    #+#              #
#    Updated: 2025/04/11 19:18:52 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc
FLAGS 		= -Wall -Wextra -Werror
CFLAGS		= -Iinc

HEADERS 	:= -I ./inc -I $(LIBMLX)/include
LIBS		:= $(l)

   