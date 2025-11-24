#include "Based.hpp"

Based::Based(std::string in, std::string out, std::string s1, std::string s2){
    err = 0;
    infile = new std::ifstream(in.c_str());
    if (!infile->is_open())
    {
        std::cout << "unable to open FILENAME" << std::endl;
        err += 1;
    }
    if (err == 0)
        outfile = new std::ofstream(out.c_str());
    if (!err && !outfile->is_open())
    {
        std::cout << "unable to open OUTFILE" << std::endl;
        err += 2;  
    }
    this->s1 = s1;
    this->s2 = s2;
    
}

Based::~Based(){
    if (err & 1 || err == 0)
        delete infile;
    if (err & 2 || err == 0)
        delete outfile;
    std::cout << "BASED Destroyed" << std::endl;
}

void Based::execute(void)
{
    if (err)
        return ;
    std::string tmp;
    std::string line;
    std::string search_line;
    while (std::getline(*infile, line))
    {
        search_line = line;
        line = "";
        while (true)
        {
            int start = search_line.find(s1);
            if (start == -1)
            {
                if (search_line.empty())
                    line += search_line;
                break;
            }
            line = line.substr(0, start);
            line += s2;
            search_line = search_line.substr(start + s1.length(), search_line.length() - start);
        }
        *outfile << line << std::endl;
    }
    infile->close();
    outfile->close();
}