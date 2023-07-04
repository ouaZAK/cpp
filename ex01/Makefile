NAME = PhoneBook
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
SRC =	main.cpp \
		Classes.cpp

OBJ = $(SRC:.cpp=.o)

%.o : %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $^ -o $@

clean : 
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all