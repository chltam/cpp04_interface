NAME := interface

CXX := c++

CXXFLAGS :=  -g -Werror -Wextra -Wall -std=c++98

SCRS := main.cpp AMateria.cpp Ice.cpp Cure.cpp\
        Character.cpp\
        MateriaSource.cpp

OBJS := $(SCRS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all