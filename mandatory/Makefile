# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 08:49:17 by mdegache          #+#    #+#              #
#    Updated: 2025/01/14 11:01:19 by mdegache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Ilib/minilibx
MLX_DIR = lib/minilibx

PRINTF_FILES = lib/ft_printf/ft_printf.c\
				lib/ft_printf/params.c\
				lib/ft_printf/params2.c\
				lib/ft_printf/side_func.c\
				lib/ft_printf/side_pointer.c\
				
GNL_FILES = lib/GNL/get_next_line.c\
        	lib/GNL/get_next_line_utils.c\
			
LIBFT_FILES = lib/libft/ft_itoa.c\

SRC = main.c\
		free_funct.c\
		map/verif_map.c\
		map/build_map.c\
		map/check_map.c\
		map/flood_fill.c\
		window/ft_window.c\
		window/init_image.c\
		move/move_player.c\
		move/all_moves.c\
		move/all_move_bis.c\

OBJ = $(SRC:.c=.o)
OBJ_LIB = $(GNL_FILES:.c=.o) $(PRINTF_FILES:.c=.o) $(LIBFT_FILES:.c=.o)

$(NAME): $(OBJ) $(OBJ_LIB)
	@if [ ! -f $(MLX_DIR)/libmlx.a ]; then \
		make --no-print-directory -C $(MLX_DIR);\
	fi
	@$(CC) $(OBJ) $(OBJ_LIB) -L$(MLX_DIR) -lmlx -lm -lX11 -lXext -o $(NAME)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_LIB)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re