# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tntini <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/10 08:50:31 by tntini            #+#    #+#              #
#    Updated: 2018/10/11 11:39:24 by tntini           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

OBJ = ls_lib.a

MAIN = main.c\

SRC =	action.c\
		ft_itoa.c\
	 	ft_list.c\
	 	ft_ls.c\
	 	ft_memcpy.c\
	 	ft_putchar.c\
	 	ft_putchar_fd.c\
	 	ft_putendl.c\
	 	ft_putnbr.c\
	 	ft_putnbr_fd.c\
	 	ft_putstr.c\
	 	ft_strcmp.c\
	 	ft_strjoin.c\
	 	ft_strlen.c\
		ft_strnew.c\
		print_ls.c\
		main.c

OSRC = 	action.o\
	  	ft_itoa.o\
	  	ft_list.o\
	  	ft_ls.o\
	  	ft_memcpy.o\
	  	ft_putchar.o\
	  	ft_putchar_fd.o\
	  	ft_putendl.o\
	  	ft_putnbr.o\
	  	ft_putnbr_fd.o\
	  	ft_putstr.o\
	  	ft_strcmp.o\
	  	ft_strjoin.o\
	  	ft_strlen.o\
	  	ft_strnew.o\
	  	print_ls.o\
		main.o\

FLAGS = -Wall -Wextra -Werror

CC = gcc

HEADER = ft_ls.h

all:$(NAME)
	@echo "\033[92mCopiling $(NAME) ...\033[0m"

$(NAME):$(OBJ)
	$(CC) $(FLAGS) -o ft_ls $(MAIN) $(OBJ)

$(OBJ):$(OSRC)
	ar rc $(OBJ) $(OSRC)

$(OSRC):
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm $(OSRC)

fclean: clean
	rm ft_ls
	rm -f ls_lib.a
re:	fclean all
