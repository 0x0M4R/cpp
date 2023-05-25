SRCS = main.cpp Zombie.cpp randomChump.cpp
NAME = phonebook
CC_FLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = ${SRCS:.c=.o}
all:	${NAME}

${NAME}:
	c++ ${CC_FLAGS} ${SRCS} -o ${NAME}
clean:
	rm -f ${NAME}
fclean:	clean
re:	fclean all