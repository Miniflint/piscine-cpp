SRC	= src/main.cpp src/Zombie.cpp src/newZombie.cpp src/randomChump.cpp
B	= ./objs

OBJS    = $(SRC:.cpp=.o)
FLAGS	= -Wall -Wextra -Werror -pedantic -std=c++98
ifeq ($(DEBUG),debug)
	FLAGS += -fsanitize=address -g3
endif
NAME	= hehe
CC	= g++ $(FLAGS)

all: $(NAME)

makedir :
	@mkdir -p $(B)

$(NAME) : makedir $(OBJS)
	@printf "Compiling\n"
	@$(CC) $(OBJS) -o $(NAME)

%.o : %.cpp
	@printf "Compiling %-33.333s\r" $<
	@$(CC) -c $< -o $@

clean:
	@printf "Removing .o\n"
	@rm -f $(OBJS)

fclean: clean
	@printf "Removing exec\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean clean all re
