#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "A dog has been initialized" << std::endl;
    this->_type = "DOG";
    return ;
}

Dog::Dog(std::string type) : Animal(type)
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
        this->_type = anim.getType();
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
