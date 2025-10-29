#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "A Cat has been initialized" << std::endl;
    this->_type = "CAT";
    this->_brain = new Brain();
    return ;
}

Cat::Cat(std::string name) : Animal(name)
{
    std::cout << "default Cat constructor with name" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(Cat const &anim) : Animal(anim)
{
    std::cout << "default Cat constructor reference" << std::endl;
    this->_brain = new Brain((const Brain &)anim._brain);
}

Cat &Cat::operator=(Cat &anim)
{
    if (this != &anim)
        this->_type = anim.getType();
    this->_brain = new Brain((const Brain &)anim._brain);
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "A Cat has been Destroyed" << std::endl;
    delete this->_brain;
    return ;
}

void Cat::makeSound(void) const
{
    std::cout << "MOOOOOOOOOOOOOOOOOOOOOEW" << std::endl;
}

void	Cat::getIdeas(void)
{
    int i;

    i = 0;
    while (i < 10)
    {
        std::cout << "Idea " << i << ": " << *this->_brain->getIdeaAtIndex(i) << std::endl;
        i++;
    }
}

void    Cat::setIdea(std::string idea)
{
    this->_brain->addIdea(idea);
}