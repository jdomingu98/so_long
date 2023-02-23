# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/31 16:11:00 by jdomingu          #+#    #+#              #
#    Updated: 2023/02/20 21:14:11 by jdomingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=42
LIBMLX	= MLX42
LIBFT	= libft
GNL_DIR = get_next_line
HEADERS = -I $(GNL_DIR) -I $(LIBMLX)/include -I $(LIBFT)
LIBS	= -ldl -lglfw -pthread -lm
#LIBS_MAC42 = -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
SRCS	= src/check_map.c src/path_finding.c src/free_allocated.c src/load_sprites.c  \
	  src/move_player.c src/print_map.c src/so_long.c $(GNL_SRCS)
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
OBJS	= $(SRCS:.c=.o)

all: libft libmlx $(NAME)

libft:	
	make -C $(LIBFT)

libmlx:	
	make -C $(LIBMLX)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(SRCS) $(LIBFT)/libft.a $(LIBMLX)/libmlx42.a $(HEADERS) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT)
	make clean -C $(LIBMLX)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)/libft.a
	rm -rf $(LIBMLX)/libmlx42.a

re: fclean all

.PHONY: all clean fclean re libmlx libft
