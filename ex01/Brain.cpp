#include "Brain.hpp"


Brain &Brain::operator=(Brain &brain)
{
    if (this != &brain)
        getIdeas(brain, brain._curr_index);
    return (*this);
}

Brain::Brain(void) : _curr_index(0)
{
    std::cout << "a brain has been created" << std::endl;
    return ;
}

Brain::Brain(const Brain &src) : _curr_index(src._curr_index)
{
    std::cout << "a brain has been with a copy" << std::endl;
	getIdeas(src, src._curr_index);
    return ;
}

Brain::~Brain()
{
    std::cout << "a brain has been destroyed" << std::endl;
    return ;
}
void    Brain::addIdea(std::string idea)
{
    if (this->_curr_index >= 100)
        return ;
    this->_ideas[this->_curr_index] = idea;
    this->_curr_index += 1;
}

void    Brain::getIdeas(const Brain &src, int size_ideas)
{
	int	i = 0;

	while (i < size_ideas && i < 100)
	{
		if (src._ideas[i].length() > 0)
			this->addIdea(src._ideas[i]);
		i++;
	}
}

const std::string    *Brain::getIdeaAtIndex(int index) const
{
	if (index < 100)
		return (&this->_ideas[index]);
	return (NULL);
}