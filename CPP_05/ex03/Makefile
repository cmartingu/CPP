NAME		=	exec

SRC			=	src/main.cpp					\
				src/Bureaucrat.cpp				\
				src/AForm.cpp					\
				src/PresidentialPardonForm.cpp	\
				src/RobotomyRequestForm.cpp		\
				src/ShrubberyCreationForm.cpp	\
				src/Intern.cpp

OBJS		=	$(SRC:.cpp=.o)

COMPILE		=	c++

FLAGS		=	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILE) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	
re:	fclean all

run: all clean

.cpp.o:
	${COMPILE} ${FLAGS} -c $< -o ${<:.cpp=.o}

.PHONY:	all clean fclean re run