# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcumbe-q <jcumbe-q@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 10:48:17 by jcumbe-q          #+#    #+#              #
#    Updated: 2024/07/08 10:48:36 by jcumbe-q         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SONAME = libft.so
CC = cc
FLAGS = -Wall -Wextra -Werror -I./ -c
FILES = $(wildcard src/*.c)
HEADERS = $(wildcard includes/*.h) 

OBJ = $(FILES:src/%.c=%.o)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(HEADERS) $(OBJ)

$(OBJ): $(FILES)
		gcc $(FLAGS) $(HEADERS) $(FILES)

all: $(NAME)

clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
		rm -f $(SONAME)
re: fclean all

so:		
		gcc -shared -o $(SONAME) -fPIC $(FILES)

.PHONY: all clean fclean re so bonus
