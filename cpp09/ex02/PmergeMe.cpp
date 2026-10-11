#include "PmergeMe.hpp"
#include <iomanip>
#include <time.h>


int PmergeMe::string_to_int(const std::string &str)
{
    std::stringstream ss(str);
    int value;
    char leftover;

    if (!(ss >> value) || (ss >> leftover) || value < 0)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    return value;
}

std::vector<int> PmergeMe::getVector() const {
    return numbers;
}

std::deque<int> PmergeMe::getDeque() const {
    return numbersDq;
}

PmergeMe::PmergeMe(std::vector<int> _numbers) : numbers(_numbers)
{
    numbers = sortVec(numbers);
}

PmergeMe::PmergeMe(std::deque<int> _numbers) : numbersDq(_numbers)
{
    numbersDq = sortDq(numbersDq);
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &o) : numbers(o.numbers), numbersDq(o.numbersDq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &o)
{
    if (this != &o)
    {
        numbers = o.numbers;
        numbersDq = o.numbersDq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}





// ============================ VECTOR ============================



void PmergeMe::insertSortedVec(std::vector<int> &mainChain, int value, int low, int high)
{
    std::vector<int>::iterator first = mainChain.begin() + low;
    std::vector<int>::iterator last = mainChain.begin() + high;
    std::vector<int>::iterator pos = std::lower_bound(first, last, value);
    mainChain.insert(pos, value);
}

std::vector<std::pair<int,int> > PmergeMe::create_pairsVec(std::vector<int> v, int &odd)
{
    std::vector<std::pair<int,int> > p;
    size_t i = 0;
    odd = -1;

    while (i + 1 < v.size())
    {
        int val1 = v[i];
        int val2 = v[i + 1];
        if (val1 > val2)
            p.push_back(std::pair<int,int>(val1, val2));
        else
            p.push_back(std::pair<int,int>(val2, val1));
        i += 2;
    }
    if (i < v.size())
        odd = v[i];
    return p;
}


// cpp — vector version
std::vector<std::pair<int,int> > PmergeMe::alignPendVec(std::vector<std::pair<int,int> > pairs, std::vector<int> &mainChain)
{
    std::vector<std::pair<int,int> > sorted;
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        for (std::vector<std::pair<int,int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        {
            if (it->first == mainChain[i])
            {
                sorted.push_back(*it);   // moves this pair's (large, small) into position i,
                pairs.erase(it);         // matching the main chain's new, recursively-sorted order
                break;
            }
        }
    }
    return sorted;
}

std::vector<int> PmergeMe::sortVec(std::vector<int> values)
{
    if (values.size() <= 1)
        return values;

    int odd = -1;
    std::vector<std::pair<int,int> > pairs = create_pairsVec(values, odd);

    std::vector<int> largerValues;
    for (size_t i = 0; i < pairs.size(); i++)
        largerValues.push_back(pairs[i].first);

    std::vector<int> mainChain = sortVec(largerValues);
    pairs = alignPendVec(pairs, mainChain);


    size_t size = pairs.size();
    size_t cnt = size;
    if (odd != -1)
        cnt++;

    // Step 0: pend[0] is paired with the smallest main element — insert directly, no search
    if (size > 0)
        mainChain.insert(mainChain.begin(), pairs[0].second);

    // Jacobsthal-driven insertion of the rest
    size_t prev = 1;
    size_t curr = 3;
    while (prev < cnt)
    {
        size_t end = curr;
        if (end > cnt)
            end = cnt;
        for (size_t i = end; i > prev; i--)
        {
            int value;
            int partner = -1;

            if (i <= size)
            {
                value = pairs[i - 1].second;
                partner = pairs[i - 1].first;
            }
            else
                value = odd;

            size_t idx = mainChain.size();
            if (partner != -1)
            {
                for (size_t k = 0; k < mainChain.size(); k++)
                {
                    if (mainChain[k] == partner)
                    {
                        idx = k;
                        break;
                    }
                }
            }
            insertSortedVec(mainChain, value, 0, idx);
        }
        size_t next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }

    return mainChain;
}




















// ============================ DEQUE ============================



void PmergeMe::insertSortedDq(std::deque<int> &mainChain, int value, int low, int high)
{
    std::deque<int>::iterator first = mainChain.begin() + low;
    std::deque<int>::iterator last = mainChain.begin() + high;
    std::deque<int>::iterator pos = std::lower_bound(first, last, value);
    mainChain.insert(pos, value);
}

std::deque<std::pair<int,int> > PmergeMe::create_pairsDq(std::deque<int> v, int &odd)
{
    std::deque<std::pair<int,int> > p;
    size_t i = 0;
    odd = -1;

    while (i + 1 < v.size())
    {
        int val1 = v[i];
        int val2 = v[i + 1];
        if (val1 > val2)
            p.push_back(std::pair<int,int>(val1, val2));
        else
            p.push_back(std::pair<int,int>(val2, val1));
        i += 2;
    }
    if (i < v.size())
        odd = v[i];
    return p;
}

// cpp — deque version, identical logic
std::deque<std::pair<int,int> > PmergeMe::alignPendDq(std::deque<std::pair<int,int> > pairs, std::deque<int> &mainChain)
{
    std::deque<std::pair<int,int> > sorted;
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        for (std::deque<std::pair<int,int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        {
            if (it->first == mainChain[i])
            {
                sorted.push_back(*it);
                pairs.erase(it);
                break;
            }
        }
    }
    return sorted;
}

std::deque<int> PmergeMe::sortDq(std::deque<int> values)
{
    if (values.size() <= 1)
        return values;

    int odd = -1;
    std::deque<std::pair<int,int> > pairs = create_pairsDq(values, odd);

    std::deque<int> largerValues;
    for (size_t i = 0; i < pairs.size(); i++)
        largerValues.push_back(pairs[i].first);

    std::deque<int> mainChain = sortDq(largerValues);
    pairs = alignPendDq(pairs, mainChain);


    size_t size = pairs.size();
    size_t cnt = size;
    if (odd != -1)
        cnt++;

    if (size > 0)
        mainChain.insert(mainChain.begin(), pairs[0].second);

    size_t prev = 1;
    size_t curr = 3;
    while (prev < cnt)
    {
        size_t end = curr;
        if (end > cnt)
            end = cnt;
        for (size_t i = end; i > prev; i--)
        {
            int value;
            int partner = -1;

            if (i <= size)
            {
                value = pairs[i - 1].second;
                partner = pairs[i - 1].first;
            }
            else
                value = odd;

            size_t idx = mainChain.size();
            if (partner != -1)
            {
                for (size_t k = 0; k < mainChain.size(); k++)
                {
                    if (mainChain[k] == partner)
                    {
                        idx = k;
                        break;
                    }
                }
            }
            insertSortedDq(mainChain, value, 0, idx);
        }
        size_t next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }

    return mainChain;
}