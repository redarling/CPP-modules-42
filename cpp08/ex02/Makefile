SRCS		=	main.cpp

OBJS		=	${SRCS:.cpp=.o}

NAME		=	Mutant

RM			=	rm -f

CXX			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

all:		${NAME}

${NAME}:	${OBJS}
			${CXX} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp
			${CXX} ${CFLAGS} -c $< -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
