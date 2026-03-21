NAME = Animal

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.hpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)
# Filter out .hpp from OBJS
OBJS := $(filter-out %.o, $(OBJS)) main.o Animal.o Cat.o Dog.o Brain.o
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
rm -f $(OBJS)

fclean: clean
rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
