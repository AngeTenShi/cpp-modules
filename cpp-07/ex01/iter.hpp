#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void    iter(T *addr, int size, F map)
{
    int i = 0;
    while (i < size)
    {
        map(addr[i]);
        i++;
    }
}

#endif