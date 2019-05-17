#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 18:37:19 by lreznak-          #+#    #+#              #
#    Updated: 2019/02/20 06:44:09 by lreznak-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = \
	calc.c dcl_back.c dcl_begin.c dcl_creator.c dcl_el_printer.c dcl_end.c dcl_forward.c dcl_len.c dcl_printer.c \
	dcl_printer_back.c dcl_push_back.c dcl_rpn.c dcl_take_n.c ft_atoi.c ft_bzero.c ft_check_brackets.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isoperand.c ft_isprint.c ft_isspace.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
	ft_lstdelone.c ft_lstfree.c ft_lstfreeone.c  ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstnew_unsafe.c ft_memalloc.c \
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
	ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c \
	ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c  ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c is_left_orient.c make_rpn.c \
	make_matrix.c ft_nputchar.c \

OBJ = *.o

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC) -I inc
	@ar rc $(NAME)  $(OBJ)
clean:
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re: fclean all

