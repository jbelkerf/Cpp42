#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string rep){
    char    c = 0;
    int     n = 0;
    float   f = 0;
    double  d = 0;
    bool    no_int = false;
    bool    no_char = false;

    if  (rep.length() == 1 && !std::isdigit(rep[0]))
    {
        c = rep[0];
        n = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (rep.find('.') != std::string::npos && rep.find('f') != std::string::npos)
    {
        f = std::strtof(rep.c_str(), NULL);
        d = static_cast<double>(f);
        if (d >= INT_MIN && d <= INT_MAX)
        {
            n = static_cast<int>(f);
        }
        else
            no_int = true;
        if (no_int == false && n >=0 && n <= 255)
        {
            c = static_cast<char>(n);
        }
        else
            no_char = true;

    }
    else if (rep[0] == '\'')
    {
        c = rep[1];
        n = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if(rep.find('.') != std::string::npos){
        d = std::strtod(rep.c_str(), NULL);
        f = static_cast<float>(d);
        if (d >= INT_MIN && d <= INT_MAX)
        {
            n = static_cast<int>(f);
        }
        else
            no_int = true;
        if (!no_int && n >=0 && n <= 255)
        {
            c = static_cast<char>(n);
        }
        else
            no_char = true;
    }
    else if (rep == "nan" || rep == "+inf" || rep == "-inf" || rep == "nanf" || rep == "+inff" || rep == "-inff")
    {
        if (rep == "nanf" || rep == "+inff" || rep == "-inff") {
            f = std::strtof(rep.c_str(), NULL);
            d = static_cast<double>(f);
        } else {
            d = std::strtod(rep.c_str(), NULL);
            f = static_cast<float>(d);
        }
        no_char = no_int = true;
    }
    else
    {
        n = std::atoi(rep.c_str());
        d = static_cast<double>(n);
        f = static_cast<float>(n);
        if (no_int == false && n >=0 && n <= 255)
        {
            c = static_cast<char>(n);
        }
        else
            no_char = true;
    }

    if (no_char || n >= 128)
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (n >= 0 && n <= 127 && std::isprint(c))
        std::cout << "char: '" << c << "'" <<std::endl;
    else if (n >= 0 && n <= 127)
        std::cout << "char: Non displayable" << std::endl;

    if (no_int)
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
        std::cout << "int: "<< n << std::endl;
    if (rep == "+inff" || rep == "+inf") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else{
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}