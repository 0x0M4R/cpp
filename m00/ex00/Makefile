SRCS = megaphone.cpp
NAME = megaphone
CC_FLAGS = -Wall -Wextra -Werror -std=c++98 megaphone.cpp
OBJS = ${SRCS:.c=.o}
all:	${NAME}

.c.o: ${SRCS}
	c++ -c ${CC_FLAGS} -o $@ $<
clean:
	rm -f ${NAME}
fclean:	clean
re:	fclean all