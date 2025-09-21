#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;

    phonebook.index = 0;
    while (true)
    {
        std::cout << "enter your command: ADD, SEARCH, EXIT"<<std::endl;
        std::cin >> command;
        if (command.compare("EXIT"))
            return  (0);
        if (command.compare("ADD"))
            phonebook.add();
        if (command.compare("SEARCH"))
            phonebook.search();
    }
}
