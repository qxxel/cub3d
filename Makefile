# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 11:34:08 by agerbaud          #+#    #+#              #
#    Updated: 2024/12/15 22:19:52 by agerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
LIBFTDIR = libft
MLX_DIR = minilibx-linux
LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
SRCS =	sources/cub3d.c					\
		sources/parsing/get_color.c		\
		sources/parsing/get_image.c		\
		sources/parsing/get_map.c		\
		sources/parsing/parse_args.c	\
		sources/parsing/parse_file.c	\
		sources/parsing/parse_map.c		\
		sources/render/actions.c		\
		sources/render/destroyer.c		\
		sources/render/displayer.c		\
		sources/render/ft_raycast.c		\
		sources/render/hooks.c			\
		sources/render/minimap.c		\
		sources/utils/clear_image.c		\
		sources/utils/count_lines.c		\
		sources/utils/err.c				\
		sources/utils/ft_bzero_int.c	\
		sources/utils/put_in_table.c	\
		sources/utils/put_pixel.c

CC = cc -Wall -Wextra -Werror -MMD -g3
LFLAGS = -lXext -lX11 -lm

OBJECTS = $(SRCS:.c=.o)
DEPENDENCIES = $(SRCS:.c=.d)


all: libft mlx $(NAME)

run:	all
		./$(NAME) map.cub

$(NAME): $(OBJECTS) $(LIBFT) $(MLX)
	$(CC) -o $@ $^ $(LFLAGS)

libft:
	$(MAKE) -C $(LIBFTDIR)

mlx:
	$(MAKE) -C $(MLX_DIR) all

-include $(DEPENDENCIES)

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	$(RM) $(OBJECTS) $(DEPENDENCIES)
	$(MAKE) -C $(LIBFTDIR) $@
	$(MAKE) -C $(MLX_DIR) $@

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) $@

re: fclean all

.PHONY: all clean fclean re libft mlx