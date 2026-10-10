#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> _numbers):numbers(_numbers){
    
    numbers = sortVec(numbers);
    std::cout << "After:  ";
    for (size_t k = 0; k < numbers.size();k++){
        std::cout << numbers[k] << " ";
    }
    std::cout << std::endl;
    
}

int PmergeMe::string_to_int(const std::string &str)
{
    std::stringstream ss(str);
    int value;
    char leftover;

    if (!(ss >> value) || (ss >> leftover) || value < 0)
    {
        std::cerr << "Error: invalid input" << std::endl;
        exit(1);
    }
    return value;
}

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

    // reconnect (erase-based) — after this, pairs[k] corresponds to mainChain[k]
    std::vector<std::pair<int,int> > sorted;
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        for (std::vector<std::pair<int,int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        {
            if (it->first == mainChain[i])
            {
                sorted.push_back(*it);
                pairs.erase(it);
                break;
            }
        }
    }
    pairs = sorted;

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
            int partner = -1; // -1 = no partner, search full range (the odd/extra element)

            if (i <= size)
            {
                value = pairs[i - 1].second;
                partner = pairs[i - 1].first;
            }
            else
                value = odd;

            // find partner's CURRENT position in mainChain to bound the search
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


PmergeMe::PmergeMe(std::deque<int> _numbers) : numbersDq(_numbers)
{
    numbersDq = sortDq(numbersDq);
    std::cout << "After:  ";
    for (size_t k = 0; k < numbersDq.size(); k++)
        std::cout << numbersDq[k] << " ";
    std::cout << std::endl;
}

void PmergeMe::insertSortedDq(std::deque<int> &mainChain, int value, int low, int high)
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

std::deque<std::pair<int,int> > PmergeMe::create_pairsDq(std::deque<int> v, bool &hasLeftover, int &leftoverValue)
{
    std::deque<std::pair<int,int> > p;
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

std::deque<int> PmergeMe::sortDq(std::deque<int> values)
{
    if (values.size() <= 1)
        return values;

    bool hasLeftover = false;
    int leftoverValue = 0;
    std::deque<std::pair<int,int> > pairs = create_pairsDq(values, hasLeftover, leftoverValue);

    std::deque<int> largerValues;
    for (size_t i = 0; i < pairs.size(); i++)
        largerValues.push_back(pairs[i].first);

    std::deque<int> mainChain = sortDq(largerValues);

    std::deque<bool> used(pairs.size(), false);
    std::deque<int> orderedPend;
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

    for (size_t i = 0; i < orderedPend.size(); i++)
        insertSortedDq(mainChain, orderedPend[i], 0, mainChain.size());

    if (hasLeftover)
        insertSortedDq(mainChain, leftoverValue, 0, mainChain.size());

    return mainChain;
}