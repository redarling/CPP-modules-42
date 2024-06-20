SRCS		=	main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

OBJS		=	${SRCS:.cpp=.o}

NAME		=	ex03

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