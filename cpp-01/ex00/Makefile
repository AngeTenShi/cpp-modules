NAME            =		ex00
C               =       c++
RED             =       \033[0;31m
CYAN            =       \033[0;36m
COLOR_OFF       =       \033[0m\0
YELLOW          =       \033[0;33m
FLAGS           =       -Wall -Wextra -Werror -std=c++98

SRCS            =       main.cpp newZombie.cpp randomChump.cpp Zombie.cpp


all:   $(SRCS) $(NAME)

$(NAME):
						$(C) $(FLAGS) $(SRCS) -o $(NAME)

clean:
						@rm -rf $(NAME)
						@echo "$(YELLOW) Files has been removed."

re:                     clean all

.PHONY:         all clean re
