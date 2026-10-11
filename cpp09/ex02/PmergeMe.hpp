#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>

class PmergeMe{
    private:
        std::vector<int> numbers;
        std::deque<int> numbersDq;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        PmergeMe(std::vector<int> numbers);
        PmergeMe(std::deque<int> numbers);

        std::vector<int> getVector() const;
        std::deque<int> getDeque() const;

        static int string_to_int(const std::string &str);

        // vector version
        std::vector<std::pair<int,int> > create_pairsVec(std::vector<int> v, int &odd);
        std::vector<int> sortVec(std::vector<int> values);
        void insertSortedVec(std::vector<int> &mainChain, int value, int low, int high);

        // deque version
        std::deque<std::pair<int,int> > create_pairsDq(std::deque<int> v, int &odd);
        std::deque<int> sortDq(std::deque<int> values);
        void insertSortedDq(std::deque<int> &mainChain, int value, int low, int high);

        //align
        std::vector<std::pair<int,int> > alignPendVec(std::vector<std::pair<int,int> > pairs, std::vector<int> &mainChain);
        std::deque<std::pair<int,int> > alignPendDq(std::deque<std::pair<int,int> > pairs, std::deque<int> &mainChain);
};

#endif