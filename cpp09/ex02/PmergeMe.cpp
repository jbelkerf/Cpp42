#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int _count, char **nums){
    for (int i = 1; i < _count; i++)
    {
        int number = atoi(nums[i]);
        numbers.push_back(number);
    }
    count = _count;
    numbers = sort(numbers);
    print_list(numbers);
}

// --- helper: binary search insert, bounded or full-range ---
void PmergeMe::insertSorted(std::vector<int> &mainChain, int value, int low, int high)
{
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (mainChain[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    mainChain.insert(mainChain.begin() + low, value);
}

// --- create_pairs: now also tracks original pairing (larger -> smaller) ---
std::vector<std::pair<int,int> > PmergeMe::create_pairs(std::vector<int> v, bool &hasLeftover, int &leftoverValue)
{
    std::vector<std::pair<int,int> > p;
    size_t i = 0;
    hasLeftover = false;

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
    if (i < v.size()) // odd leftover
    {
        hasLeftover = true;
        leftoverValue = v[i];
    }
    return p;
}

// --- sort: flat in, flat out ---
std::vector<int> PmergeMe::sort(std::vector<int> values)
{
    if (values.size() <= 1)
        return values;

    bool hasLeftover = false;
    int leftoverValue = 0;
    std::vector<std::pair<int,int> > pairs = create_pairs(values, hasLeftover, leftoverValue);

    // extract larger values to recurse on
    std::vector<int> largerValues;
    for (size_t i = 0; i < pairs.size(); i++)
        largerValues.push_back(pairs[i].first);

    // recurse
    std::vector<int> mainChain = sort(largerValues);

    // reconnect: for each value now in mainChain, find which pair it came
    // from (by matching .first), to retrieve its .second partner, in order
    std::vector<bool> used(pairs.size(), false);
    std::vector<int> orderedPend;
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (!used[j] && pairs[j].first == mainChain[i])
            {
                orderedPend.push_back(pairs[j].second);
                used[j] = true;
                break;
            }
        }
    }

    // insert each pend value into mainChain (simple left-to-right order,
    // full-range search for now — Jacobsthal ordering comes later)
    for (size_t i = 0; i < orderedPend.size(); i++)
        insertSorted(mainChain, orderedPend[i], 0, mainChain.size());

    // insert leftover, if any, full-range
    if (hasLeftover)
        insertSorted(mainChain, leftoverValue, 0, mainChain.size());

    return mainChain;
}

void PmergeMe::print_list(std::vector<int> v){
    std::vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        std::cout << *it << ", ";
        it++;
    }
    std::cout << std::endl;
}