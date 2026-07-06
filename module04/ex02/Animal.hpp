#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal(std::string name);
		Animal(Animal const &animal);
		Animal &operator=(Animal &anim);
		virtual ~Animal(void);
		std::string getType(void) const;
		virtual void makeSound(void) const = 0;
};

#endif
