#include "Based.hpp"

Based::Based(std::string in, std::string out, std::string _s1, std::string _s2):infile(in.c_str()), outfile(), s1(_s1), s2(_s2)
{
    err = 0;
    if (s1.empty())
        err = 1;
    if (!infile.is_open())
    {
        std::cout << "unable to open FILENAME" << std::endl;
        err += 1;
    }
    if (err == 0)
        outfile.open(out.c_str());
    if (!err && !outfile.is_open())
    {
        std::cout << "unable to open OUTFILE" << std::endl;
        err += 2;  
    }
    this->s1 = s1;
    this->s2 = s2;
    
}

Based::~Based(){
    if (infile.is_open())
        infile.close();
    if (outfile.is_open())
        outfile.close();
    std::cout << "BASED Destroyed" << std::endl;
}

void Based::execute(void)
{
    if (err)
        return ;
    std::string line;
    std::string search_line;
    
    while (std::getline(infile, line))
    {
        search_line = line;
        line = "";
        while (true)
        {
            int start = search_line.find(s1);
            if (start == -1)
            {
                line += search_line;
                break;
            }
            line += search_line.substr(0, start);
            line += s2;
            search_line = search_line.substr(start + s1.length(), search_line.length() - start);
        }
        if (infile.eof())
            outfile << line ;
        else
            outfile << line << std::endl;
    }
    if (infile.is_open())
        infile.close();
    if (outfile.is_open())
        outfile.close();
}