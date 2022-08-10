RST	= \e[0m
GRN = \e[32m
RED	= \e[31m

SRC	= src/main.cpp src/PhoneBook.class.cpp src/Contact.class.cpp src/utils.cpp
OBJ	= $(SRC:.cpp=.o)
FLAG= -Wall -Werror -Wextra -fsanitize=address -std=c++98
CC	= c++ $(FLAG)
NAME= test_classes

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@printf "$(GRN)\nDone\n$(RST)"

%.o: %.cpp
	@printf "Compiling: %s %33.333s\r" $< $@
	@$(CC) -c $< -o $@

clean:
	@printf "$(RED)Removing $(OBJ)$(RST)\n"
	@rm -f $(OBJ)

fclean: clean
	@printf "$(RED)Removing executable $(NAME)$(RST)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean
