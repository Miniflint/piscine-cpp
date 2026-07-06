#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "default WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "default WrongAnimal constructor with name" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &anim) : _type(anim.getType())
{
    std::cout << "default WrongAnimal constructor reference" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &anim)
{
    if (this != &anim)
        this->_type = anim.getType();
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "default WrongAnimal Destructor" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "L'WrongAnimal ne fait PAS un son" << std::endl;
}
