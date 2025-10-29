#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "default animal constructor" << std::endl;
}

Animal::Animal(std::string name) : _name(name)
{
    std::cout << "default animal constructor with name" << std::endl;
}

Animal::Animal(Animal const &anim) : _name(anim.getType())
{
    std::cout << "default animal constructor reference" << std::endl;
}

Animal &Animal::operator=(Animal &anim)
{
    if (this != &anim)
        this->_name = anim.getType();
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "default animal Destructor" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->_name);
}

void Animal::makeSound(void) const
{
    std::cout << "L'animal fait un son" << std::endl;
}
