#include "PmergeMe.hpp"
#include <ctime>
#include <vector>
#include <deque>
#include <climits>

static bool parseInput(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return (false);
    }

    for (int i = 1; i < argc; ++i)
    {
        for (size_t j = 0; argv[i][j]; ++j)
        {
            if (!std::isdigit(argv[i][j]))
            {
                std::cerr << "Error: invalid input" << std::endl;
                return (false);
            }
        }
    }
    
    for (int i = 0; i < argc; ++i)
    {
        long long num = std::atoll(argv[i]);
        
        if (num < 0 || num > INT_MAX)
        {
            std::cerr << "Error: invalid input" << std::endl;
            return (false);
        }
    }
    
    return (true);
}

int main(int argc, char **argv)
{
    if (!parseInput(argc, argv)) return (1);

    PmergeMe<std::vector<int> >  pmergeVector;
    PmergeMe<std::deque<int> >   pmergeDeque;

    pmergeVector.fillContainer(argc, argv);
    pmergeDeque.fillContainer(argc, argv);

    pmergeVector.printContainer(BEFORE);
//--------------------------------------------------------------
    clock_t    vectorTimeStart = clock();
    pmergeVector.fordJohnsonAlgorithm();
    double          vectorTimeDuration = (clock() - vectorTimeStart) / (double)CLOCKS_PER_SEC * 1000;
//--------------------------------------------------------------
    clock_t    dequeTimeStart = clock();
    pmergeDeque.fordJohnsonAlgorithm();
    double          dequeTimeDuration = (clock() - dequeTimeStart) / (double)CLOCKS_PER_SEC * 1000;
//--------------------------------------------------------------
    pmergeVector.printContainer(AFTER);
    
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::vector: "
              << vectorTimeDuration << "ms" << std::endl;
    
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::deque: "
              << dequeTimeDuration << "ms" << std::endl;

    return (0);
}