# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreynaud <mreynaud@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 13:19:13 by mreynaud          #+#    #+#              #
#    Updated: 2025/01/08 14:57:26 by mreynaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------------     HEAD     ------------------------------- #
# -------------------------------   preamble   ------------------------------- #
NAME			= cub3d
DIR_BUILD		= .build/
DIR_INC			= include/

DIR_LIBFT		= libft/
DIR_INC_LIBFT	= $(DIR_LIBFT)
LIBFT			= $(DIR_LIBFT)libft.a

DIR_MLX 		= minilibx-linux/
DIR_INC_MLX		= $(DIR_MLX)
MLX				= $(DIR_MLX)libmlx.a

LIB 			= $(LIBFT) $(MLX)

WFLAGS			= -Wall -Werror -Wextra
IFLAGS			= -I $(DIR_INC) -I $(DIR_INC_LIBFT) -I $(DIR_INC_MLX)
DEPFLAGS		= -MMD -MP
CFLAGS			= $(WFLAGS) $(DEPFLAGS) $(IFLAGS)
LFLAGS			= -lXext -lX11 -lm

CC				= cc
RM				= rm -fr
AR				= ar -crs
MKDIR			= mkdir -p $(shell dirname $@)
ECHO			= echo

# -------------------------------    source    ------------------------------- #
include src.mk

# -------------------------------    colors    ------------------------------- #
COLOR_GREEN	= \033[0;32m
COLOR_WHITE	= \033[0m

# -------------------------------   message   ------------------------------- #
MSG_OK		= $(COLOR_GREEN)[OK]$(COLOR_WHITE)
MSG_RULE	= $(ECHO) "$(MSG_OK) $(NAME) => Rule: $@"
MSG_OBJECT	= $(ECHO) "$(basename $(notdir $@))"
MSG_OBJECTS	= $(ECHO) "$(MSG_OK) compilation object"

# -------------------------------  obj & dep  ------------------------------- #
OBJ		= $(addprefix $(DIR_BUILD), $(addsuffix .o, $(basename $(SRCS))))
DEP		= $(OBJ:.o=.d)

-include $(DEP)
# -------------------------------    RULES    ------------------------------- #
# -------------------------------     all     ------------------------------- #
.DEFAULT_GOAL	:= all
.PHONY	: all
all		: $(NAME)

# -------------------------------    cub3d    ------------------------------- #
$(NAME)	: $(OBJ) $(LIB)
	@$(MSG_OBJECTS)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@$(MSG_RULE)

# -------------------------------    object    ------------------------------- #
$(DIR_BUILD)%.o : $(DIR_SRC)%.c Makefile
	@$(MKDIR)
	$(CC) $(CFLAGS) -o $@ -c $<

# -------------------------------     lib     ------------------------------- #
$(LIB)	: FORCE
	@make -C $(dir $@)

# -------------------------------    force    ------------------------------- #
.PHONY	: FORCE
FORCE :

# -------------------------------    clean    ------------------------------- #
.PHONY	: clean
clean	:
	@make -C $(DIR_LIBFT) fclean
	@make -C $(DIR_MLX) clean
	@$(RM) $(DIR_BUILD)
	@$(MSG_RULE)

# -------------------------------    fclean    ------------------------------- #
.PHONY	: fclean
fclean	: clean
	@$(RM) $(NAME)
	@$(MSG_RULE)

# -------------------------------      re      ------------------------------- #
.PHONY	: re
re		: fclean all
	@$(MSG_RULE)

