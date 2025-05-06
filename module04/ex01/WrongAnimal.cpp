#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "default WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : _name(name)
{
    std::cout << "default WrongAnimal constructor with name" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &anim) : _name(anim.getType())
{
    std::cout << "default WrongAnimal constructor reference" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &anim)
{
    if (this != &anim)
        this->_name = anim.getType();
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "default WrongAnimal Destructor" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->_name);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "L'WrongAnimal ne fait PAS un son" << std::endl;
}
