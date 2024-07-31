SRCS		=	main.cpp AMateria.cpp \
				ICharacter.cpp IMateriaSource.cpp \
				Character.cpp Ice.cpp Cure.cpp

OBJS		=	${SRCS:.cpp=.o}

NAME		=	Interface

RM			=	rm -f

CXX			=	c++

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