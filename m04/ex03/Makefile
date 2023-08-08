SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
NAME = Interface
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