SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
NAME = Animal
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
OBJS = ${SRCS:.cpp=.o}

all:	${NAME}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${SRCS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all