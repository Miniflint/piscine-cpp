#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "iostream"

class WrongAnimal
{
	protected:
		std::string _name;
		WrongAnimal(void);
		WrongAnimal(std::string name);
		WrongAnimal(WrongAnimal const &WrongAnimal);
		WrongAnimal &operator=(WrongAnimal &anim);

	public:
		virtual ~WrongAnimal(void);
		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif
