# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edilson <edilson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 10:05:00 by edilson           #+#    #+#              #
#    Updated: 2023/12/20 03:49:35 by edilson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c makecdwork.c makecdwork2.c ft_echo_n.c ft_exit.c utile1.c utile_exit.c utils2.c dollars.c dollars2.c ft_export.c ft_unset.c check_path.c ft_quote.c

FLG = -Wall -Wextra -Werror

HEADERS = -I/opt/homebrew/opt/readline/include -I include

LIB_PATH =  -L. lib/libft.a -lreadline -L/opt/homebrew/opt/readline/lib

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