NAME = zombie
CC = c++
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp \
		Zombie.cpp \
		zombieHorde.cpp
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
