SRCS = main.cpp Fixed.cpp
NAME = fixed
CCXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
OBJS = ${SRCS:.cpp=.o}

all:	${NAME}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${SRCS} -o ${NAME}

clean:
	rm -f ${NAME} ${OBJS}

fclean:	clean

re:	fclean all