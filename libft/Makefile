# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 12:34:17 by agerbaud          #+#    #+#              #
#    Updated: 2025/01/08 16:42:40 by agerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = libft.h
SRCS =	checker/ft_isalpha.c				\
		checker/ft_isdigit.c				\
		checker/ft_isdir.c					\
		checker/ft_isalnum.c				\
		checker/ft_isascii.c				\
		checker/ft_isnum.c					\
		checker/ft_isprint.c				\
		str/ft_strlen.c						\
		str/ft_strlcpy.c					\
		str/ft_strlcat.c					\
		str/ft_strldup.c					\
		str/ft_strchr.c						\
		str/ft_strrchr.c					\
		str/ft_strncmp.c					\
		str/ft_strtrim.c					\
		str/ft_striteri.c					\
		str/ft_strmapi.c					\
		str/ft_strnstr.c					\
		str/ft_strdup.c						\
		str/ft_strjoin.c					\
		str/ft_substr.c						\
		put/ft_putchar_fd.c					\
		put/ft_putstr_fd.c					\
		put/ft_putendl_fd.c					\
		put/ft_putnbr_fd.c					\
		mem/ft_memset.c						\
		mem/ft_memchr.c						\
		mem/ft_memcpy.c						\
		mem/ft_memcmp.c						\
		mem/ft_memmove.c					\
		lst/ft_lstadd_back.c				\
		lst/ft_lstadd_front.c				\
		lst/ft_lstclear.c					\
		lst/ft_lstdelone.c					\
		lst/ft_lstiter.c					\
		lst/ft_lstlast.c					\
		lst/ft_lstmap.c						\
		lst/ft_lstnew.c						\
		lst/ft_lstsize.c					\
		others/ft_toupper.c					\
		others/ft_tolower.c					\
		others/ft_bzero.c					\
		others/ft_atoi.c					\
		others/ft_calloc.c					\
		others/ft_free_table.c				\
		others/ft_split.c					\
		others/ft_itoa.c					\
		others/ft_tablen.c					\
		ft_printf/ft_dprintf.c				\
		ft_printf/ft_printf.c				\
		ft_printf/ft_putchar_pf.c			\
		ft_printf/ft_puthexa_pf.c			\
		ft_printf/ft_putnbr_pf.c			\
		ft_printf/ft_putnbr_unsigned_pf.c	\
		ft_printf/ft_putpointer_pf.c		\
		ft_printf/ft_putstr_pf.c			\
		get_next_line/get_next_line_utils.c	\
		get_next_line/get_next_line.c		\

CC = cc -Wall -Wextra -Werror -MMD -g3

OBJECTS = $(SRCS:.c=.o)
DEPENDANCIES = $(SRCS:.c=.d)


all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -crs $@ $^

-include $(DEPENDANCIES)


%.o: %.c
	$(CC) -o $@ -c $<


clean:
	$(RM) $(OBJECTS) $(DEPENDANCIES)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all bonus clean fclean re
