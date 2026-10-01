#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int _count, char **nums){
    for (int i = 1;i < _count;i++)
    {
        int number = atoi(nums[i]);
        numbers.push_front(number);
    }
    count = _count;
    if (count % 2 == 0)
        reach = count;
    else
        reach = count -1;
    sort(numbers);
}


std::list<std::pair<int,int> > PmergeMe::create_pairs(std::list<int> l){
    int i =0;
    std::list<std::pair<int, int> > p;
    std::list<int>::iterator it = l.begin();
    while (it != l.end() && i < count -1 ){
        int val1 = *it;
        int val2 =*(++it);
        if (val1 > val2){
            p.push_back(std::pair<int , int>(val1, val2));
        }
        else{
            p.push_back((std::pair<int , int>(val2, val1)));
        }
        it++;
        i++;
    }
    return p;
}

std::list<int> PmergeMe::fill_big(std::list<std::pair<int,int> > p){
    std::list<int> new_l;
    if (p.size() == 0)
        return new_l;
    std::list<std::pair<int,int> >::iterator it = p.begin();
    while (it != p.end())
    {
        new_l.push_back(it->first);
        ++it;
    }
    it = p.begin();
    while (it != p.end())
    {
        new_l.push_back(it->second);
        ++it;
    }
    return new_l;
}

std::list<int> PmergeMe::sort(std::list<int> l){
    std::list<std::pair<int,int> > p = create_pairs(l);
    std::list<int> new_l = fill_big(p);
    if (new_l.size() == 0)
    {

        return numbers;
    }
    size_t i = 0;
    size_t size = new_l.size();
    while (i < size){
        numbers.pop_front();
        i++;
    }
    exit(1);
        std::cout << "here " << std::endl;
    std::list<int>::iterator it = new_l.end();
    it--;
    while (it != new_l.begin())
    {
        numbers.push_front(*it);
        it--;
    }
    numbers.push_front(*it);
    std::cout << "reach : " << reach << std::endl;
    std::cout << "list : " << std::endl;
    print_list(numbers);
    reach = new_l.size();
    if (reach % 2 == 1)
        reach--;
    std::list<int> nl ;
    it = new_l.begin();
    while (it != new_l.end())
    {
        nl.push_back(*it);
        it++;
    }
    // sort(nl);
    return numbers;
}


void PmergeMe::print_list(std::list<int> l) {
    std::list<int>::iterator it = l.begin();
    while (it != l.end()){
        std::cout << *it << ", " ;
        it++;
    }
    std::cout << std::endl;
}
