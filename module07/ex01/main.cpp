#include <iostream>
#include "iter.hpp"

void    non_funonconstionon(int &i)
{
    i += 1;
    std::cout << i << std::endl;
}

void    const_funconstion_const(const int &i)
{
    std::cout << i << std::endl;
}

int main(void)
{
    const unsigned int len = 5;
    int array[] = {0, 1, 2, 3, 4};
    ::iter(&array[0], len, non_funonconstionon);
    ::iter(&array[0], len, non_funonconstionon);
    ::iter(&array[0], len, non_funonconstionon);
    ::iter(&array[0], len, non_funonconstionon);
    ::iter(&array[0], len, const_funconstion_const);
}