SRCS		=	main.cpp Zombie.cpp randomChump.cpp newZombie.cpp

OBJS		=	${SRCS:.cpp=.o}

NAME		=	zombie

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
