#include <iostream>
#include <stdint.h>

struct Data
{
    int a;
    int b;
};

uintptr_t   serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data    *deserialize(uintptr_t data)
{
    return (reinterpret_cast<Data *>(data));
}

int main(void)
{
    Data *data;
    uintptr_t uint;

    data = new Data;
    data->a = 1;
    data->b = 2;
    uint = serialize(data);
    data = deserialize(uint);
    std::cout << data->a << std::endl;
    std::cout << data->b << std::endl;

    return (0);
}