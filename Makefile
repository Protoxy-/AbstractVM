##
## Makefile for AbstractVM in /home/hoerte_f/rendu/cpp_abstractvm
## 
## Made by Francois Hoertel
## Login   <hoerte_f@epitech.net>
## 
## Started on  Fri Feb 20 23:58:46 2015 Francois Hoertel
## Last update Fri Feb 27 13:50:26 2015 Francois Hoertel
##

NAME	= AbstractVM

SRC	= Exception.cpp \
	  Parser.cpp \
	  ExecData.cpp \
	  Executer.cpp \
	  MainVM.cpp \
	  Stack.cpp

OBJ	= $(SRC:.cpp=.o)

#CXXFLAGS	=	-W -Wextra -Wall -Werror -lm

CC	= g++

RM	= rm -f

$(NAME):	 $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
	$(RM) $(OBJ)

fclean:         clean
	$(RM) $(NAME)

re:             fclean all

.PHONY:         all clean re fclean
