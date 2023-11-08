# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfabre <gfabre@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 10:05:00 by edilson           #+#    #+#              #
#    Updated: 2023/11/08 13:59:13 by gfabre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c makecdwork.c makecdwork2.c utils.c utils_print.c utils2.c ft_unset.c ft_export.c ft_jsp.c ft_jsp2.c

FLG = -Wall -Wextra -Werror

HEADERS = -I/usr/local/opt/readline/include -I include

LIB_PATH =  -L. -lreadline -L/usr/local/opt/readline/lib

OBJ = $(SRC:.c=.o)

.c.o :
	gcc $(FLG) $(HEADERS) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
	cd lib ; make
	gcc $(FLG) $(OBJ) $(HEADERS) lib/libft.a $(LIB_PATH) -o $(NAME)
clean :
	cd lib ; make clean
	rm -f $(OBJ)

fclean : clean
	cd lib ; make fclean
	rm -f $(NAME)

re : fclean all