#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
        WrongCat(std::string name);
		WrongCat(WrongCat const &anim);
        WrongCat &operator=(WrongCat &anim);
		~WrongCat(void);
		virtual void makeSound(void) const;
};


#endif