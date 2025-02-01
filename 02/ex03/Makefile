CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	bsp
FILES	=	main.cpp bsp.cpp Fixed.cpp Point.cpp

OBJ		=	$(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJ) $(wildcard *.gch)

fclean: clean
	$(RM) $(NAME) $(TEST)

re: fclean all