#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **arg, int ac)
{
    for (int i = 1; i < ac; i++)
    {
        if ((std::atoi(arg[i]) == 0 && arg[i][0] != '0') || std::atoi(arg[i]) < 0)
        {
            std::cout << "Error" << std::endl;
            exit(0);
        }
        this->first_container.push_back(std::atoi(arg[i]));
        this->second_container.push_back(std::atoi(arg[i]));
    }
    return ;
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    this->first_container = other.first_container;
    this->second_container = other.second_container;
    return ;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    this->first_container = other.first_container;
    this->second_container = other.second_container;
    return (*this);
}

PmergeMe::~PmergeMe()
{
    return ;
}

void PmergeMe::insertionVector(int idx_start, int idx_end)
{
    for (int i = idx_start; i <= idx_end; i++)
    {
        int j = i;
        while (j > idx_start && this->first_container[j] < this->first_container[j - 1])
        {
            int temp = this->first_container[j];
            this->first_container[j] = this->first_container[j - 1];
            this->first_container[j - 1] = temp;
            j--;
        }
    }
}

void PmergeMe::mergeVector(int idx_start, int idx_end) {
    int idx_mid = (idx_start + idx_end) / 2;
    int i = idx_start;
    int j = idx_mid + 1;
    std::vector<int> temp;
    while (i <= idx_mid && j <= idx_end)
    {
        if (this->first_container[i] < this->first_container[j])
        {
            temp.push_back(this->first_container[i]);
            i++;
        }
        else
        {
            temp.push_back(this->first_container[j]);
            j++;
        }
    }
    if (i > idx_mid)
    {
        while (j <= idx_end)
        {
            temp.push_back(this->first_container[j]);
            j++;
        }
    }
    else
    {
        while (i <= idx_mid)
        {
            temp.push_back(this->first_container[i]);
            i++;
        }
    }
    for (size_t i = 0; i < temp.size(); i++)
    {
        this->first_container[idx_start + i] = temp[i];
    }
}

void PmergeMe::sortVector(int idx_start, int idx_end)
{
    if (idx_end - idx_start > 5)
    {
        int idx_mid = (idx_start + idx_end) / 2;
        sortVector(idx_start, idx_mid);
        sortVector(idx_mid + 1, idx_end);
        mergeVector(idx_start, idx_end);
    }
    else
        insertionVector(idx_start, idx_end);
}

void PmergeMe::insertionList(int idx_start, int idx_end)
{
    std::list<int>::iterator it = this->second_container.begin();
    std::advance(it, idx_start);
    std::list<int>::iterator end = this->second_container.begin();
    std::advance(end, idx_end);
    for (std::list<int>::iterator it2 = it; it2 != end; ++it2)
    {
        std::list<int>::iterator j = it2;
        while (j != it && *j < *(--j))
        {
            int temp = *j;
            *j = *(--j);
            *(--j) = temp;
        }
    }
}

void PmergeMe::mergeList(int idx_start, int idx_end)
{
    int i = idx_start;
    int idx_mid = (idx_start + idx_end) / 2;
    int j = idx_mid + 1;
    std::list<int>::iterator begin = this->second_container.begin();
    std::advance(begin, idx_start);
    std::list<int>::iterator mid = this->second_container.begin();
    std::advance(mid, idx_mid + 1);
    std::list<int> temp;
    while (i <= idx_mid && j <= idx_end)
    {
        if (*begin < *mid)
        {
            temp.push_back(*begin);
            i++;
            begin++;
        }
        else
        {
            temp.push_back(*mid);
            j++;
            mid++;
        }
    }
    if (i > idx_mid)
    {
        while (j <= idx_end)
        {
            temp.push_back(*mid);
            j++;
            mid++;
        }
    }
    else
    {
        while (i <= idx_mid)
        {
            temp.push_back(*begin);
            i++;
            begin++;
        }
    }
    std::list<int>::iterator it = temp.begin();
    for (int i = idx_start; i <= idx_end; i++)
    {
        this->second_container.insert(it, *it);
        it++;
    }
}

void PmergeMe::sortList(int idx_start, int idx_end)
{
    if (idx_end - idx_start > 5)
    {
        int idx_mid = (idx_start + idx_end) / 2;
        sortList(idx_start, idx_mid);
        sortList(idx_mid + 1, idx_end);
        mergeList(idx_start, idx_end);
    }
    else
        insertionList(idx_start, idx_end);
}

void printList(std::list<int> list)
{
    for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void printVector(std::vector<int> vect)
{
    for (size_t i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::run()
{
    std::cout << "Before : ";
    printVector(this->first_container);
    timeval start;
    gettimeofday(&start, NULL);
    this->sortVector(0, this->first_container.size() - 1);
    timeval end;
    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    gettimeofday(&start, NULL);
    this->sortList(0, this->second_container.size() - 1);
    gettimeofday(&end, NULL);
    double elapsed2 = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    std::cout << "After : ";
    printVector(this->first_container);
    printList(this->second_container);
    std::cout << "Time to process a range of " << this->first_container.size() << " elements with std::vector : " << elapsed << " microsecondes" << std::endl;
    std::cout << "Time to process a range of " << this->second_container.size() << " elements with std::list : " << elapsed2 << " microsecondes" << std::endl;
}