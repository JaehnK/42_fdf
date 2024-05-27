# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 13:13:05 by jaehukim          #+#    #+#              #
#    Updated: 2024/05/27 21:09:44 by jaehukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
HEADR = fdf.h
CC = cc
CFLAGS = -g -Wall -Werror -Wextra

LIB = ./libft/libft.a \

SUBDIR = ./libft

SRCS = ft_main.c \
	ft_check_map.c\
	ft_parse_map.c\
	ft_draw.c \
	ft_bresenham.c \
	ft_isometric.c \
	ft_generate_points.c \
	ft_colour.c \
	ft_keyctrl.c \
	ft_utils.c \

MLX = ./minilibx-linux/

OBJS = $(SRCS:%.c=%.o)

all : $(NAME)
 
%.o: %.c
	$(CC) -g -I minilibx-linux -Imlx_linux -O3 -c $< -o $@

$(NAME) : $(OBJS)
		@make  -C ./minilibx-linux/
		@make re -C ./libft
		$(CC) $(OBJS) -L$(MLX) -g -lmlx_Linux -I$(MLX) -L$(SUBDIR) $(LIB) -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@make clean -C ./minilibx-linux/
	@make clean -C ./libft
	rm -rf $(OBJS)


fclean: clean
	@make fclean -C ./libft
	@make fclean -C ./libft
	rm -rf $(NAME)
		
re: fclean all

.PHONY : all clean fclean re
