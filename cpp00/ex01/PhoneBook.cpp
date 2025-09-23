/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:45:03 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/09/23 12:24:27 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// void    PhoneBook::add(void)
// {
//     std::string tmp;

//     std::cout << "enter your first name " << std::endl;
//     std::cin >> tmp;
//     contacts[index].setfname(tmp);

//     std::cout << "enter your last name " << std::endl;
//     std::cin >> tmp;
//     contacts[index].setlname(tmp);
//     std::cout << "enter your nickname " << std::endl;
//     std::cin >> tmp;
//     contacts[index].setnname(tmp);
//     std::cout << "enter your phone number " << std::endl;
//     std::cin >> tmp;
//     contacts[index].setpnumber(tmp);
//     std::cout << "enter your darkest secret " << std::endl;
//     std::cin >> tmp;
//     contacts[index].setdsecret(tmp);
//     index = (index + 1) % 8;
// }

std::string replace_unwanted(std::string str)
{
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (!std::isprint(str[i]))
            str[i] = ' ';
    }
    return (str);
}

bool is_all_white(std::string str)
{
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (!std::isspace(str[i]))
            return (false);
    }
    return (true);
}
std::string gnl(std::string output)
{
    std::string input = "";
    
    std::cout  << output<< std::endl;
    if (!std::getline(std::cin, input, '\n'))
    {
        std::cout << "EOF detected, exiting..." << std::endl;
        exit(1);
    }
    input = replace_unwanted(input);
    if (input.empty() || is_all_white(input))
    {
        std::cout << "empty input, please try again" << std::endl;
        return (gnl(output));
    }
    return (input);
}

void    PhoneBook::add(void)
{
    contacts[index].setfname(gnl("enter your first name "));
    contacts[index].setlname(gnl("enter your last name "));
    contacts[index].setnname(gnl("enter your nickname "));
    contacts[index].setpnumber(gnl("enter your phone number "));
    contacts[index].setdsecret(gnl("enter your darkest secret "));
    index = (index + 1) % 8;
}

std::string resize(std::string str)
{
    std::string tmp;
    if (str.length() == 0)
        return ("empty");
    if (str.length() > 10)
    {
        tmp = str.substr(0, 9);
        tmp = tmp.append(".");
        return (tmp);
    }
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

using std::setw; //! to be removed
void PhoneBook::search(void)
{
    int index;
    std::cout << " -------------------------------------------" << std::endl;
    std::cout << "|" <<"  index   " << "|" << "first_name" << "|" << "last_name "<< "|" << " nickname " << "|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << "|"
        << std::setw(10) << i  << "|"
        << std::setw(10) << resize(contacts[i].getfname()) << "|"
        << std::setw(10) << resize(contacts[i].getlname())<< "|"
        << std::setw(10) << resize(contacts[i].getnname())<< "|"
        << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "enter the index of the contact you want to display" << std::endl;
    std:: cin >> index;
    if (std::cin.fail() || index < 0 || index > 7)
    {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "invalid index" << std::endl;
        return ;
    }
    if (contacts[index].getfname().empty())
    {
        std::cout << "this contact is empty" << std::endl;
        return ;
    }
    std::cout << "first name: " << contacts[index].getfname() << std::endl;
    std::cout << "last name: " << contacts[index].getlname() << std::endl;
    std::cout << "nickname: " << contacts[index].getnname() << std::endl;
    std::cout << "phone number: " << contacts[index].getpnumber() << std::endl;
    std::cout << "darkest secret: " << contacts[index].getdsecret() << std::endl;
    
}

