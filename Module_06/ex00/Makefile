# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 16:14:29 by zouaraqa          #+#    #+#              #
#    Updated: 2023/09/19 16:15:46 by zouaraqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cast
CC = c++
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g
SRC =	main.cpp \
		ScalarConverter.cpp

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
