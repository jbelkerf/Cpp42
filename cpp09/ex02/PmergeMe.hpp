#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <deque>
#include <iterator>
#include <utility>
#include <sys/time.h>
#include <iomanip>
#include <sstream>

class PmergeMe{
    private:
        std::vector<int> numbers;
        std::vector<std::pair<int,int> > pairs;
        std::deque<int> numbersDq;
    public:
    static int string_to_int(const std::string &str);
        PmergeMe(std::vector<int> numbers);
        PmergeMe(std::deque<int> numbers);

        

        // vector version
        std::vector<std::pair<int,int> > create_pairsVec(std::vector<int> v, int &odd);
        std::vector<int> sortVec(std::vector<int> values);
        void insertSortedVec(std::vector<int> &mainChain, int value, int low, int high);

        // deque version
        std::deque<std::pair<int,int> > create_pairsDq(std::deque<int> v, bool &hasLeftover, int &leftoverValue);
        std::deque<int> sortDq(std::deque<int> values);
        void insertSortedDq(std::deque<int> &mainChain, int value, int low, int high);
};

#endif