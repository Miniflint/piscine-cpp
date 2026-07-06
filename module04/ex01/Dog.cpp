#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "A dog has been initialized" << std::endl;
    this->_type = "DOG";
    this->_brain = new Brain();
    return ;
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "default Dog constructor with name" << std::endl;
    this->_brain = new Brain();
}

Dog::Dog(Dog const &anim) : Animal(anim)
{
    std::cout << "default Dog constructor reference" << std::endl;
    this->_brain = new Brain((const Brain &)anim._brain);
}

Dog &Dog::operator=(Dog &anim)
{
    if (this != &anim)
        this->_type = anim.getType();
    this->_brain = new Brain((const Brain &)anim._brain);
    return (*this);
}

Dog::~Dog(void)
{
    delete this->_brain;
    std::cout << "A dog has been Destroyed" << std::endl;
    return ;
}

void Dog::makeSound(void) const
{
    std::cout << "WOOOOOOOOOOOOOOOOOOOOOOF" << std::endl;
}

void	Dog::getIdeas(void)
{
    int i;

    i = 0;
    while (i < 10)
    {
        std::cout << "Idea " << i << ": " << this->_brain->getIdeaAtIndex(i) << std::endl;
        i++;
    }
}

void    Dog::setIdea(std::string idea)
{
    this->_brain->addIdea(idea);
}