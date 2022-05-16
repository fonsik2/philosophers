# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 10:13:12 by smdyan            #+#    #+#              #
#    Updated: 2022/05/11 14:53:38 by smdyan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c\
	  init.c\
	  utils.c\
	  actions.c

HEADER = ./

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(HEADER) -MD

include $(wildcard *.d)

$(NAME): $(OBJ) Makefile
	$(CC) $(OBJ) -o $(NAME) -pthread

clean:
	rm -f $(OBJ)
	rm -f $(wildcard *.d)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
