SRCS		=	ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp

OBJS		=	${SRCS:.cpp=.o}

NAME		=	ScavTrap

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