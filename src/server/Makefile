CXX=	g++

CXXFLAG=	-W -Wall -Wextra -Werror -g3

BUILDING=	\033[0;32m[*] BUILDING SERVER...\033[0;37m

SRC=	$(wildcard *.cpp)

OBJ=	$(SRC:.cpp=.o)

NAME=	launch_server

all:	$(OBJ)
	@echo "$(BUILDING)"
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAG) -I include
	cp $(NAME) ../../

clean:
	rm -rf .*.swp .*.swo *~

fclean:	clean
	rm -rf *.o
	rm -rf $(NAME) ../../$(NAME)

re: fclean all
