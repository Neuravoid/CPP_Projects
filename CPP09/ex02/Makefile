NAME= PmergeMe
SRCS= PmergeMe.cpp main.cpp
OBJS= $(SRCS:.cpp=.o)
CXX=c++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98

all : make

make: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY = all make fclean clean re