# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 11:57:23 by zouaraqa          #+#    #+#              #
#    Updated: 2023/10/06 09:58:38 by zouaraqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = stl
CC = c++
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
SRC =	main.cpp \
		Span.cpp

OBJ = $(SRC:.cpp=.o)

%.o:%.cpp
	@$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $^ -o $@

clean : 
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
