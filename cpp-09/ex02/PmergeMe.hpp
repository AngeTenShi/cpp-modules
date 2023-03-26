#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <sys/time.h>



class PmergeMe
{
    public:
        PmergeMe(char **arg, int ac);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        void mergeVector(int idx_start, int idx_end);
        void insertionVector(int idx_start, int idx_end);
        void sortVector(int idx_start, int idx_end);
        void sortList(int idx_start, int idx_end);
        void mergeList(int idx_start, int idx_end);
        void insertionList(int idx_start, int idx_end);
        void run();

    private:
        std::vector<int> first_container;
        std::list<int>   second_container;
};