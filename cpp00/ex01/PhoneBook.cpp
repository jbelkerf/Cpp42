#include "PhoneBook.hpp"

void    PhoneBook::add(void)
{
    std::string tmp;

    std::cout << "enter your first name " << std::endl;
    std::cin >> tmp;
    contacts[index].setfname(tmp);
    std::cout << "enter your last name " << std::endl;
    std::cin >> tmp;
    contacts[index].setlname(tmp);
    std::cout << "enter your nickname " << std::endl;
    std::cin >> tmp;
    contacts[index].setnname(tmp);
    std::cout << "enter your phone number " << std::endl;
    std::cin >> tmp;
    contacts[index].setpnumber(tmp);
    std::cout << "enter your darkest secret " << std::endl;
    std::cin >> tmp;
    contacts[index].setdsecret(tmp);
    index = (index + 1) % 8;
}

std::string resize(std::string str)
{
    std::string tmp;
    int         reminder;
    if (str.length() == 0)
        return ("  empty   ");
    if (str.length() > 10)
    {
        tmp = str.substr(0, 9);
        tmp = tmp.append(".");
        return (tmp);
    }
    reminder = 10 - str.length();
    for (int i = 0; i < reminder; i++)
        str += " ";
    return (str);
}

void    PhoneBook::setindex(int n)
{
    index = n;
}

int    PhoneBook::getindex(void)
{
    return (index);
}

void PhoneBook::search(void)
{
    for (int i = 0; i < 8; i++)
    {
        std::cout <<"    " << i << "     "<< resize(contacts[index].getfname()) << "|" << resize(contacts[index].getlname())<< "|" << resize(contacts[index].getnname())<< std::endl;
    }
}

