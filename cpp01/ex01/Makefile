SRCS		=	main.cpp Zombie.cpp zombieHorde.cpp

OBJS		=	${SRCS:.cpp=.o}

NAME		=	zombieHorde

RM		=	rm -f

CXX		=	c++

CFLAGS		=  -Wall -Wextra -Werror -std=c++98

all:		${NAME}

${NAME}:	${OBJS}
		${CXX} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all fclean clean re