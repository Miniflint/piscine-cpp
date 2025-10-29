#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "A WrongCat has been initialized" << std::endl;
    this->_type = "WrongCat";
    this->_brain = new Brain();
    return ;
}

WrongCat::WrongCat(std::string name) : WrongAnimal(name)
{
    std::cout << "default WrongCat constructor with name" << std::endl;
    this->_brain = new Brain();
}

WrongCat::WrongCat(WrongCat const &anim) : WrongAnimal(anim)
{
    std::cout << "default WrongCat constructor reference" << std::endl;
    this->_brain = new Brain((const Brain &)anim._brain);
}

WrongCat &WrongCat::operator=(WrongCat &anim)
{
    if (this != &anim)
        this->_type = anim.getType();
    this->_brain = new Brain((const Brain &)anim._brain);
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "A WrongCat has been Destroyed" << std::endl;
    delete this->_brain;
    return ;
}

void WrongCat::makeSound(void) const
{
    std::cout << "the wrong animal does not make any sound" << std::endl;
}

void	WrongCat::getIdeas(void)
{
    int i;

    i = 0;
    while (i < 10)
    {
        std::cout << "Idea " << i << ": " << this->_brain->getIdeaAtIndex(i) << std::endl;
        i++;
    }
}