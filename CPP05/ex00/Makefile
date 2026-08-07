NAME= Bureaucrat
SRCS= main.cpp Bureaucrat.cpp 
OBJS= $(SRCS:.cpp=.o)
CXXFLAGS= -Wall -Werror -Wextra -std=c++98
CXX = c++

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

