NAME = phonebook

# Derleyici ve bayraklar
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Kaynak dosyalar
SRCS = Search_Phonebook.cpp Add_Phonebook.cpp Contact.cpp main.cpp

# Nesne dosyaları
OBJS = $(SRCS:.cpp=.o)

# Kurallar
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all