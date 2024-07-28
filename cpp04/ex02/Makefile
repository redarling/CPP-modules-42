SRCS		=	main.cpp Cat.cpp Dog.cpp AAnimal.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

OBJS		=	${SRCS:.cpp=.o}

NAME		=	Polymorphism_v3.0

RM			=	rm -f

CPP			=	c++

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