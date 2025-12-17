NAME = Fixed
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Fixed.cpp

all: $(NAME)
$(NAME): $(SRCS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)
fclean: clean