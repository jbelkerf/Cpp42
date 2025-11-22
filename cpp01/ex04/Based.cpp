#include "Based.hpp"

Based::Based(std::string in, std::string out, std::string s1, std::string s2){
    err = 0;
    infile = new std::ifstream(in);
    if (!infile->is_open())
    {
        std::cout << "unable to open FILENAME" << std::endl;
        err += 1;
    }
    if (err == 0)
        outfile = new std::ofstream(out);
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
    while (std::getline(*infile, line))
    {
        std::cout << "line : " << line << std::endl;
        std::cout << "s1 : " << s1 << std::endl;
        std::cout << "s2 : " << s2 << std::endl;
        while (true)
        {
            // break;
            int start = line.find(s1);
            std::cout << "here is start " << start << std::endl;
            if (start == -1)
                break;
            tmp = line.substr(0, start);
            tmp += s2;
            tmp += line.substr(start + s1.length(), line.length());
            line = tmp;
        }
        *outfile << line << std::endl;
    }
    infile->close();
    outfile->close();
}