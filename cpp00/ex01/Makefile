NAME = PhoneBook

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)
	c++ $(FLAGS) PhoneBook.hpp Contact.hpp   Contact.cpp PhoneBook.cpp  main.cpp -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean