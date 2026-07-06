#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "default animal constructor" << std::endl;
}

Animal::Animal(std::string name) : _type(name)
{
    std::cout << "default animal constructor with name" << std::endl;
}

Animal::Animal(Animal const &anim) : _type(anim.getType())
{
    std::cout << "default animal constructor reference" << std::endl;
}

Animal &Animal::operator=(Animal &anim)
{
    if (this != &anim)
        this->_type = anim.getType();
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "default animal Destructor" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->_type);
}

void Animal::makeSound(void) const
{
    std::cout << "L'animal fait un son" << std::endl;
}
