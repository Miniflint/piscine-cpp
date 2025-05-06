SRCS	:= Cat.cpp Dog.cpp Animal.cpp Brain.cpp main.cpp
OBJS	:= $(SRCS:%.cpp=%.o)

FLAGS	:= -Wall -Wextra -Werror -std=c++98
CC		:= /usr/bin/g++

TARGET	:= animals

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

.PHONY: re fclean clean all