#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <list>
#include <utility>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

class PmergeMe{
    private:
        std::list<int> numbers;
        std::list<std::pair<int, int> > pairs;
        int count;
        int reach;
    public:
        PmergeMe(int count, char **numbers);
        void print_list(std::list<int>) ;
        std::list<std::pair<int,int> > create_pairs(std::list<int>);
        std::list<int> sort(std::list<int>);
        std::list<int> fill_big(std::list<std::pair<int,int> > );
};

#endif