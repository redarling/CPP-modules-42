SRCS		=	Bureaucrat.cpp AForm.cpp\
				GradeTooLowException.cpp GradeTooHighException.cpp \
				ShrubberyCreationForm.cpp \
				PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
				NotSignedException.cpp Intern.cpp main.cpp \

OBJS		=	${SRCS:.cpp=.o}

NAME		=	ex03

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
