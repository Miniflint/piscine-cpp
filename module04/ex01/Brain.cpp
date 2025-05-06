#include "Brain.hpp"

Brain::Brain(void) : _curr_index(0)
{
    std::cout << "a brain has been created" << std::endl;
    return ;
}

Brain::~Brain()
{
    return ;
}

void    Brain::addIdea(std::string idea)
{
    if (this->_curr_index >= 100)
        return ;
    this->_ideas[this->_curr_index] = idea;
    this->_curr_index += 1;
}