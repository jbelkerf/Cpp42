#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

class PmergeMe{
    private:
        std::vector<int> numbers;
        std::vector<std::pair<int,int> > pairs;
        int count;
    public:
        PmergeMe(int count, char **numbers);
        void print_list(std::vector<int> v) ;
        std::vector<std::pair<int,int> > create_pairs(std::vector<int> v, bool &hasLeftover, int &leftoverValue);
        std::vector<int> sort(std::vector<int> values);
        void insertSorted(std::vector<int> &mainChain, int value, int low, int high);
};

#endif