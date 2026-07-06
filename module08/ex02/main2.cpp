#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "MutantStack.hpp"

int main(int ac, char **av)
{
	MutantStack<int> mstack_pop;
	MutantStack<int> mstack_iter;
	if (ac < 2)
		return ((std::cout << "Not enough arguments" << std::endl), 1);
	for (int i = 1; i < ac; i++)
	{
		int j;
		std::stringstream buff(av[i]);
		buff >> j;
		if (buff.fail() || !buff || !buff.eof())
			std::cout << "Error on: " << av[1] << std::endl;
		std::cout << "Adding: " << av[i] << std::endl;
		mstack_pop.push(j);
		mstack_iter.push(j);
	}
    std::cout << "Popping: " << std::endl;
    while (!mstack_pop.empty())
    {
        int i = mstack_pop.top();
        mstack_pop.pop();
        std::cout << i << std::endl;
    }
    {
        MutantStack<int>::iterator it = mstack_iter.begin();
        MutantStack<int>::iterator ite = mstack_iter.end();
        std::cout << "Iterator: " << std::endl;
        while (it != ite)
	    {
            // *it = *it + 1;
	    	std::cout << *it << std::endl;
	    	++it;
	    }
    }
    {
        MutantStack<int>::const_iterator it = mstack_iter.begin();
        MutantStack<int>::const_iterator ite = mstack_iter.end();
        std::cout << "Const_iterator: " << std::endl;
        while (it != ite)
	    {
            //*it = *it + 1;
	    	std::cout << *it << std::endl;
	    	++it;
	    }
    }
    {
        MutantStack<int>::reverse_iterator it = mstack_iter.rbegin();
        MutantStack<int>::reverse_iterator ite = mstack_iter.rend();
        std::cout << "Reverse_iterator: " << std::endl;
        while (it != ite)
	    {
            //*it = *it + 1;
	    	std::cout << *it << std::endl;
	    	++it;
	    }
    }
    {
        MutantStack<int>::const_reverse_iterator it = mstack_iter.rbegin();
        MutantStack<int>::const_reverse_iterator ite = mstack_iter.rend();
        std::cout << "Const_reverse_iterator: " << std::endl;
        while (it != ite)
	    {
            //*it = *it + 1;
	    	std::cout << *it << std::endl;
	    	++it;
	    }
    }
}
