#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "iostream"

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &WrongAnimal);
        WrongAnimal &operator=(WrongAnimal &anim);
		virtual ~WrongAnimal(void);
		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif
