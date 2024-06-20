SRCS		=	main.cpp Zombie.cpp zombieHorde.cpp

OBJS		=	${SRCS:.cpp=.o}

NAME		=	ex01

RM		=	rm -f

CPP		=	c++

CFLAGS		=  -Wall -Wextra -Werror -std=c++98

all:		${NAME}

${NAME}:	${OBJS}
		${CPP} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all fclean clean re