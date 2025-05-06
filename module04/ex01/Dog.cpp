#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "A dog has been initialized" << std::endl;
    this->_name = "DOG";
    this->_brain = new Brain();
    return ;
}

Dog::Dog(std::string name) : Animal(name)
{
    std::cout << "default Dog constructor with name" << std::endl;
    this->_brain = new Brain();
}

Dog::Dog(Dog const &anim) : Animal(anim)
{
    std::cout << "default Dog constructor reference" << std::endl;
    this->_brain = new Brain();
}

Dog &Dog::operator=(Dog &anim)
{
    if (this != &anim)
    {
        this->_name = anim.getType();
        this->_brain = new Brain();
    }
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "A dog has been Destroyed" << std::endl;
    delete this->_brain;
    return ;
}

void Dog::makeSound(void) const
{
    std::cout << "WOOOOOOOOOOOOOOOOOOOOOOF" << std::endl;
}
