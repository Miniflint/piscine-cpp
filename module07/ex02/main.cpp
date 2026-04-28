#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

# define MAX_NBR 128
int main(void)
{
    const unsigned int max = 8;
    std::cout << "===========init first array t (operator[] + default constructor)===========" << std::endl;
    Array<int>  t(max);
    for (unsigned int i = 0; i < max; i++) {
        t[i] = i - 1;
        std::cout << "t: " << t[i] << std::endl;
    }
    Array<int> t2;
    std::cout << "===========copy t in t2 (operator=)===========" << std::endl;
    t2 = t;
    for (unsigned int i = 0; i < max; i++) {
        std::cout << "t2: " << t2[i] << std::endl;
    }
    std::cout << "===========modify t2 (operator[] + deepcopy)===========" << std::endl;
    for (unsigned int i = 0; i < max; i++) {
        t2[i] = i + 1;
        std::cout << "t2: " << t2[i] << std::endl;
    }
    std::cout << "=========== init t3 from source t (copy constructor)===========" << std::endl;
    Array<int> t3(t);
    std::cout << "===========modify t3 (operator[] + deepcopy)===========" << std::endl;
    for (unsigned int i = 0; i < max; i++) {
        t3[i] = i;
        std::cout << "t3: " << t3[i] << std::endl;
    }
    std::cout << "===========display all t (operator[] + check deepcopy)===========" << std::endl;
    std::cout << "t" << " \t|" << "t2" << "\t|" << "t3" << std::endl;
    std::cout << "-------------------" << std::endl;
    for (unsigned int i = 0; i < max; i++) {
        std::cout << t[i] << " \t|" << t2[i] << "\t|" << t3[i] << std::endl;
    }
    std::cout << "===========check out of bound > limit (std::exception)===========" << std::endl;
    try {
        std::cout << t[8];
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "===========check out of bound < 0 (std::exception)===========" << std::endl;
    try {
        std::cout << t[-1];
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}