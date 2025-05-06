#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "A Cat has been initialized" << std::endl;
    this->_name = "CAT";
    this->_brain = new Brain();
    return ;
}

Cat::Cat(std::string name) : Animal(name)
{
    std::cout << "default Cat constructor with name" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(Cat const &anim) : Animal(anim)
{
    std::cout << "default Cat constructor reference" << std::endl;
    this->_brain = new Brain();
    *this->_brain = *anim.getBrain();
}

Cat &Cat::operator=(Cat &anim)
{
    if (this != &anim)
    {
        this->_name = anim.getType();
        this->_brain = new Brain();
        *this->_brain = *anim.getBrain();
    }
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "A Cat has been Destroyed" << std::endl;
    delete this->_brain;
    return ;
}

void Cat::makeSound(void) const
{
    std::cout << "MOOOOOOOOOOOOOOOOOOOOOEW" << std::endl;
}

Brain *Cat::getBrain(void) const
{
    return (this->_brain);
}