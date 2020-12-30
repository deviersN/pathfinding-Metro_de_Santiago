##
## EPITECH PROJECT, 2019
## Michelin
## File description:
## Makefile
##

CXX	= g++

RM	= rm -rf

SRC	= 	src/Rutas.cpp	\
		src/Core.cpp	\
		src/Ride.cpp	\
		src/Station.cpp \
	  	src/Grapher.cpp \
		src/Map.cpp		\
		src/PathFinder.cpp

OBJ	= $(SRC:.cpp=.o)

NAME	= swole_michelin

CXXFLAGS= -W -Wall -Wextra -Iinclude -g3 -ggdb

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(SRC) $(CXXFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

a: all clean

.PHONY: all clean fclean re a
