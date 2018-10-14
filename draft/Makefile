# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfatton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/30 00:05:23 by lfatton           #+#    #+#              #
#    Updated: 2018/07/03 06:29:54 by lfatton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, norm, git, clean, fclean, re

NAME = fractol

SRC_PATH = srcs

SRC_NAME =	main.c \

SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = objs

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INCL_NAME = fractol.h

INCL_PATH = includes

MLX_INCL_PATH = ./minilibx

LIBFT_INCL_PATH = ./libft/includes

INCLS = $(addprefix $(INCL_PATH)/,$(INCL_NAME))

IFLAGS = -I $(INCL_PATH) -I $(LIBFT_INCL_PATH) -I $(MLX_INCL_PATH)

LDLIBFT = -L ./libft -lft

LDLMX = -L ./minilibx -lmlx -lXext -lX11

#LDLIBS = -lft -lmlx -lXext -lX11

#FRMFLAGS = -framework OpenGL -framework AppKit

CC = clang

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(INCLS)
	$(MAKE) -C libft
	$(CC) $(FRMFLAGS) $(OBJS) $(LDLIBFT) $(LDLMX) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

norm:
	norminette $(SRCS) $(INCLS)

git: fclean
	git add -A
	git status

clean:
	$(RM) $(OBJS)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all
