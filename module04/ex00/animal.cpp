#include "animal.hpp"

Dog::Dog(void)
{
    std::cout << "A dog has been initialized" << std::endl;
    this->_name = "DOG";
    return ;
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

Cat::Cat(void)
{
    std::cout << "A Cat has been initialized" << std::endl;
    this->_name = "CAT";
    return ;
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

Animal::Animal(void)
{
    std::cout << "default animal constructor" << std::endl;
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

std::string WrongAnimal::getType(void) const
{
    return (this->_name);
}

void WrongAnimal::makeSound(void) const
{
    if (this->_name  == "DOG")
        std::cout << "not woof" << std::endl;
    else if (this->_name == "CAT")
        std::cout << "not meow" << std::endl;
}