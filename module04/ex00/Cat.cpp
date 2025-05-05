#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "A Cat has been initialized" << std::endl;
    this->_name = "CAT";
    return ;
}

Cat::Cat(std::string name) : Animal(name)
{
    std::cout << "default Cat constructor with name" << std::endl;
}

Cat::Cat(Cat const &anim) : Animal(anim)
{
    std::cout << "default Cat constructor reference" << std::endl;
}

Cat &Cat::operator=(Cat &anim)
{
    if (this != &anim)
        this->_name = anim.getType();
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "A Cat has been Destroyed" << std::endl;
    return ;
}

void Cat::makeSound(void) const
{
    std::cout << "MOOOOOOOOOOOOOOOOOOOOOEW" << std::endl;
}
