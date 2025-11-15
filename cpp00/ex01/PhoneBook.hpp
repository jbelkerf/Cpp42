/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:45:05 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/11/15 10:47:05 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

std::string gnl(std::string output);

class PhoneBook
{
    Contact contacts[8];
    int     index;

    public:
        void    add(void);
        void    search(void);
        
        void    setindex(int n);
        int     getindex(void);
};

# endif
