NAME = Form
SRCS = Bureaucrat.cpp Form.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all