<<<<<<< HEAD
NAME = scavtrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
=======
NAME = ScavTrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
>>>>>>> 1f377b0e7598102e5ad0de0c1fed8cf1682a1cb7

fclean: clean
	rm -f $(NAME)

re: fclean all
<<<<<<< HEAD

.PHONY: all clean fclean re
=======
>>>>>>> 1f377b0e7598102e5ad0de0c1fed8cf1682a1cb7
