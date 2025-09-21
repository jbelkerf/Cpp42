# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    Contact contacts[8];
    int     index;

    public:
        void    add(void);
        void search(void);
        
        void setindex(int n);
        int getindex(void);
};

# endif
