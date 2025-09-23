/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:45:09 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/09/23 10:45:10 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;

    phonebook.setindex(0);
    while (true)
    {
        std::cout << "enter your command: ADD, SEARCH, EXIT"<<std::endl;
        std::cin >> command;
        if (!command.compare("EXIT"))
            return  (0);
        if (!command.compare("ADD"))
            phonebook.add();
        if (!command.compare("SEARCH"))
            phonebook.search();
    }
}
