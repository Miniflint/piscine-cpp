SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)
FLAGS = -Werror -Wextra -Wall -std=c++98 
CC = c++ $(FLAGS)

NAME = megaphone

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@printf "Done\n"

%.o: %.cpp
	@printf "Compiling object\n"
	@$(CC) -c $< -o $@

clean:
	@printf "Cleaning...\n"
	@rm -f $(OBJ)

fclean: clean
	@printf "Cleaning executable\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
