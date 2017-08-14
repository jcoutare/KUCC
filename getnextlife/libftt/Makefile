#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 14:58:59 by jcoutare          #+#    #+#              #
#    Updated: 2017/05/04 13:35:13 by jcoutare         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = gcc

INCLUDES += -I libft.h

CFLAGS += -Wall -Wextra -Werror $(INCLUDES)

SRC =	ft_putstr.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_putnbr.c \
		ft_putchar.c \
		ft_memalloc.c \
		ft_isalnum.c \
		ft_bzero.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isalnum.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strjoin.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_memdel.c \
		ft_strnew.c	\
		ft_strdel.c	\
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_itoa.c	\
		ft_lstmap.c \
		ft_lstiter.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstnew.c \
		ft_print_words_tables.c \
		ft_strsplit.c \
		ft_list_clear.c \
		ft_list_size.c \
		ft_list_at.c \
		ft_list_push_back.c \
		ft_list_reverse.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f libft.a
re: fclean all
