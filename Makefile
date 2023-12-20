# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 10:05:00 by edilson           #+#    #+#              #
#    Updated: 2023/12/14 16:58:32 by gfabre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c makecdwork.c makecdwork2.c ft_echo_n.c ft_exit.c ft_slash.c utile1.c utile_exit.c utils2.c dollars.c dollars2.c ft_export.c ft_unset.c parcing.c parcing2.c parcingdbl.c parcingdbl2.c

FLG = -Wall -Wextra -Werror

HEADERS = -I/usr/local/opt/readline/include -I include

LIB_PATH =  -L. lib/libft.a -lreadline -L/usr/local/opt/readline/lib

OBJ = $(SRC:.c=.o)

.c.o :
	gcc $(FLG) $(HEADERS) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
	cd lib ; make
	gcc $(FLG) $(OBJ) $(HEADERS) $(LIB_PATH) -o $(NAME)
clean :
	cd lib ; make clean
	rm -f $(OBJ)

fclean : clean
	cd lib ; make fclean
	rm -f $(NAME)

re : fclean all