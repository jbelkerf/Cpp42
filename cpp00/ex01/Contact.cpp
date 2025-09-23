/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelkerf <jbelkerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:45:22 by jbelkerf          #+#    #+#             */
/*   Updated: 2025/09/23 12:05:02 by jbelkerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setfname(std::string name)
{
    first_name = name;
}
void Contact::setlname(std::string name)
{
    last_name = name;
}
void Contact::setnname(std::string name)
{
    nickname = name;
}
void Contact::setpnumber(std::string number)
{
    phone_number = number;
}
void Contact::setdsecret(std::string secret)
{
    darkest_secret = secret;
}
std::string Contact::getfname(void)
{
    return (first_name);
}
std::string Contact::getlname(void)
{
    return (last_name);
}

std::string Contact::getpnumber(void)
{
    return (phone_number);
}

std::string Contact::getdsecret(void)
{
    return (darkest_secret);
}

std::string Contact::getnname(void)
{
    return (nickname);
}