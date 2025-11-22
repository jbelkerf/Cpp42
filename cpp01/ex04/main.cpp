#include "Based.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "usage : ./BASED FILENAME S1 S2" << std::endl;
        return 1;
    }
    Based b(av[1], std::string(av[1]) + std::string(".replace"), av[2], av[3]);
    b.execute();
}
