#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "A dog has been initialized" << std::endl;
    this->_name = "DOG";
    return ;
}

Dog::Dog(std::string name) : Animal(name)
{
    std::cout << "default Dog constructor with name" << std::endl;
}

Dog::Dog(Dog const &anim) : Animal(anim)
{
    std::cout << "default Dog constructor reference" << std::endl;
}

Dog &Dog::operator=(Dog &anim)
{
    if (this != &anim)
        this->_name = anim.getType();
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "A dog has been Destroyed" << std::endl;
    return ;
}

void Dog::makeSound(void) const
{
    std::cout << "WOOOOOOOOOOOOOOOOOOOOOOF" << std::endl;
}
