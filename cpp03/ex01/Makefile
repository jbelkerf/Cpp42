NAME = ClapTrap

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ClapTrap.cpp        ScavTrap.cpp       main.cpp

OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all