# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/31 16:11:00 by jdomingu          #+#    #+#              #
#    Updated: 2022/12/31 16:11:02 by jdomingu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CFLAGS	= -Wall -Wextra -Werror
LIBMLX	= ./MLX42
LIBFT	= ./libft
GNL_DIR = ./get_next_line
BUFFER_FLAG = -D BUFFER_SIZE=42
HEADERS = -I $(GNL_DIR) -I $(LIBMLX)/include -I $(LIBFT)
LIBS	= -ldl -lglfw -pthread -lm #-lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
SRCS	= src/check_map.c src/free_allocated.c src/load_sprites.c  \
		src/move_player.c src/print_map.c src/so_long.c $(GNL_SRCS)
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

libft:	
	@$(MAKE) -C $(LIBFT)

libmlx:	
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ $< $(HEADERS)

$(NAME): libft libmlx
	$(CC) $(CFLAGS) $(BUFFER_FLAG) $(SRCS) libft/libft.a MLX42/libmlx42.a $(HEADERS) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf libft/libft.a
	@rm -rf MLX42/libmlx42.a

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft
