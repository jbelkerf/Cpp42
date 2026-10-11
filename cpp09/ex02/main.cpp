#include "PmergeMe.hpp"
#include <iomanip>
#include <time.h>

static double get_time_us()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000000.0 + ts.tv_nsec / 1000.0;
}

static bool is_sorted_check(const std::vector<int> &v)
{
    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[i - 1] > v[i])
            return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    // Validation pass: exits with "Error" on stderr if any argument is bad
    std::vector<int> values;
    for (int i = 1; i < argc; i++)
        values.push_back(PmergeMe::string_to_int(argv[i]));

    std::cout << "Before: ";
    for (size_t i = 0; i < values.size(); i++)
        std::cout << values[i] << " ";
    std::cout << std::endl;

    // Vector: data management + sort
    double startVec = get_time_us();
    std::vector<int> vecData;
    for (int i = 1; i < argc; i++)
        vecData.push_back(PmergeMe::string_to_int(argv[i]));
    PmergeMe pVec(vecData);
    double timeVec = get_time_us() - startVec;

    // Deque: data management + sort
    double startDq = get_time_us();
    std::deque<int> dqData;
    for (int i = 1; i < argc; i++)
        dqData.push_back(PmergeMe::string_to_int(argv[i]));
    PmergeMe pDq(dqData);
    double timeDq = get_time_us() - startDq;

    std::vector<int> sortedVec = pVec.getVector();
    std::deque<int> sortedDq = pDq.getDeque();

    // Sanity check: both results sorted and identical
    if (!is_sorted_check(sortedVec)
        || sortedVec.size() != sortedDq.size()
        || !std::equal(sortedVec.begin(), sortedVec.end(), sortedDq.begin()))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << "After:  ";
    for (size_t i = 0; i < sortedVec.size(); i++)
        std::cout << sortedVec[i] << " ";
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << values.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << values.size()
              << " elements with std::deque  : " << timeDq << " us" << std::endl;

    return 0;
}