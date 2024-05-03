##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC    =	main.cpp 	\
			Camera.cpp 	\
			Point3D.cpp 	\
			Ray.cpp 	\
			Rectangle3D.cpp 	\
			Sphere.cpp 	\
			Plane.cpp 	\
			Vector3D.cpp 	\
			SfmlUI.cpp 	\


OBJ    =    $(SRC:.cpp=.o)

NAME	=	a.out

CXXFLAGS = -std=c++20 -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system

PATH_TO_CHECKER = /home/${USER}/coding-style-checker

all:	$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(CXXFLAGS) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

tests_run:
		./tests/test.sh

git:
	echo -e "*.a\n*.o\n*#*#*\n#*\n.#*\n*~\n" > .gitignore
	echo -e "vgcore*\n*.log\na.out\n.vscode*" >> .gitignore
	echo $(NAME) >> .gitignore

style:
	$(PATH_TO_CHECKER)/coding-style.sh . .
	echo; grep -v MAJOR:C-O1 coding-style-reports.log || true; echo
	rm -f coding-style-reports.log
