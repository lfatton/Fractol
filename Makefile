# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfatton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/30 00:05:23 by lfatton           #+#    #+#              #
#    Updated: 2018/10/25 17:26:27 by lfatton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, norm, git, clean, fclean, re

NAME = fractol

SRC_PATH = srcs

SRC_NAME =	main.c \
			environment.c \
			events.c \
			image.c \
			colors.c \
			mandelbrot.c \
			julia.c \
			burning_ship.c \
			burning_julia.c \
			tricorn.c \
			brain.c \

SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = objs

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INCL_NAME = fractol.h

INCL_PATH = includes

ifeq ($(shell uname), Darwin)
	MLX_NAME = minilibx_macos
	MLX_INCL_PATH = ./minilibx_macos
	LDLMX = -L ./minilibx_macos -lmlx
	MLXFLAGS = -framework OpenGL -framework AppKit
else
	MLX_NAME = minilibx_linux
	MLX_INCL_PATH = ./minilibx_linux
	LDLMX = -L ./minilibx_linux -lmlx
	MLXFLAGS = -lXext -lX11
endif

LIBFT_INCL_PATH = ./libft/includes

INCL = $(addprefix $(INCL_PATH)/,$(INCL_NAME))

IFLAGS = -I $(INCL_PATH) -I $(LIBFT_INCL_PATH) -I $(MLX_INCL_PATH)

LDLIBFT = -L ./libft -lft

LIBS = -lm -lpthread

CC = clang

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(INCL)
	@$(MAKE) -C $(MLX_NAME)
	@$(MAKE) -C libft
	@$(CC) $(OBJS) $(LDLIBFT) $(LDLMX) $(MLXFLAGS) $(LIBS) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

run: $(NAME)
	./$(NAME) julia

norm:
	norminette $(SRCS) $(INCL)

git: fclean
	git add -A
	git status

clean:
	@$(RM) $(OBJS)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean
	@$(MAKE) -C $(MLX_NAME) clean

re: fclean all
