NAME = ZOMBIE

FLAGS = -Wall -Wextra -Werror #-std=c++98
C = c++

SRCS = Zombie.cpp     main.cpp        newZombie.cpp   randomChump.cpp

HEADER =  Zombie.hpp  

all: $(NAME)
$(NAME): $(SRCS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)
fclean: clean