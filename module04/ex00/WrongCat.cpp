#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "A WrongCat has been initialized" << std::endl;
    this->_name = "WrongCat";
    return ;
}

WrongCat::WrongCat(std::string name) : WrongAnimal(name)
{
    std::cout << "default WrongCat constructor with name" << std::endl;
}

WrongCat::WrongCat(WrongCat const &anim) : WrongAnimal(anim)
{
    std::cout << "default WrongCat constructor reference" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &anim)
{
    if (this != &anim)
        this->_name = anim.getType();
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "A WrongCat has been Destroyed" << std::endl;
    return ;
}

void WrongCat::makeSound(void) const
{
    std::cout << "NOT MOOOOOOOOOOOOOOOOOOOOOEW" << std::endl;
}
