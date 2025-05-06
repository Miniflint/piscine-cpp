#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Brain.hpp"

class Animal
{
	protected:
		std::string _name;
		Animal(void);
		Animal(std::string name);
		Animal(Animal const &animal);
		Animal &operator=(Animal &anim);

	public:
		virtual ~Animal(void);
		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif
