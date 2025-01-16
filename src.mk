# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 13:27:43 by mreynaud          #+#    #+#              #
#    Updated: 2025/01/16 11:43:53 by agerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------------    source    ------------------------------- #

SRCS =	sources/cub3d.c						\
		sources/parsing/get_color.c			\
		sources/parsing/get_image.c			\
		sources/parsing/get_map.c			\
		sources/parsing/parse_args.c		\
		sources/parsing/parse_file.c		\
		sources/parsing/parse_map.c			\
		sources/parsing/get_textures.c		\
		sources/render/actions.c			\
		sources/render/destroyer.c			\
		sources/render/displayer.c			\
		sources/render/ft_raycast.c			\
		sources/render/hooks.c				\
		sources/render/minimap.c			\
		sources/render/texture.c			\
		sources/render/update_mouse.c		\
		sources/utils/check_line_exist.c	\
		sources/utils/clear_image.c			\
		sources/utils/count_lines.c			\
		sources/utils/err.c					\
		sources/utils/find_color_code.c		\
		sources/utils/fix_angle.c			\
		sources/utils/free_tab.c			\
		sources/utils/ft_bzero_int.c		\
		sources/utils/init_variables.c		\
		sources/utils/is_open.c				\
		sources/utils/put_in_table.c		\
		sources/utils/put_pixel.c
