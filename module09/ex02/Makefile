SRCS	:= main.cpp PmergeMe.cpp
OBJS	:= $(SRCS:%.cpp=%.o)

FLAGS	:= -Wall -Wextra -Werror -std=c++98 -g
CC		:= /usr/bin/g++

TARGET	:= PmergeMe

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

build:
	docker build -t arch .
	docker run -ti arch
prune:
	docker system prune -a --volumes

.PHONY: re fclean clean all build prune