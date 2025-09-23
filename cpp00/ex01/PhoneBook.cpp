/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:45:03 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/09/23 10:46:44 by jbelkerf         ###   ########.fr       */
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
}

