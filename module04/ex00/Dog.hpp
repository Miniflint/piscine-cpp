#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"


class Dog : public Animal
{
	public:	
		Dog(void);
        Dog(std::string name);
		Dog(Dog const &anim);
        Dog &operator=(Dog &anim);
		~Dog(void);
		virtual void makeSound(void) const;
}; 

#endif