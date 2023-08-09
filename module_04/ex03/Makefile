NAME = poly
CC = c++
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g
SRC =	main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp

OBJ = $(SRC:.cpp=.o)

%.o:%.cpp
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $^ -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all