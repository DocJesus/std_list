SRC = main.cpp

CXXFLAGS += -std=c++14 -Werror -Wextra -Wall -I./Include
LOADLIBES = -lm

OBJ = $(SRC:.cpp=.o)

NAME = list

$(NAME):	$(OBJ)
			g++ -o $(NAME) $(OBJ)

fclean: clean
		rm -f $(NAME)

clean:
		rm -f $(OBJ)

all:	$(NAME) clean

re: fclean all