/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:45:25 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/09/23 10:45:26 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    
    public:
        void setfname(std::string name);
        void setlname(std::string name);
        void setnname(std::string name);
        void setpnumber(std::string number);
        void setdsecret(std::string secret);
        
        std::string getfname(void);
        std::string getlname(void);
        std::string getnname(void);
};

# endif