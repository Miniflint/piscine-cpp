#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "iostream"

class WrongAnimal
{
	protected:
		std::string _name;

	public:
		std::string getType(void) const;
		void makeSound(void) const;
};

class Animal
{
	protected:
		std::string _name;

	public:
		Animal(void);
		~Animal(void);
		std::string getType(void) const;
		virtual void makeSound(void) const;
};

class Dog : public Animal
{
	public:	
		Dog(void);
		~Dog(void);
		virtual void makeSound(void) const;
}; 

class Cat : public Animal
{
	public:
		Cat(void);
		~Cat(void);
		virtual void makeSound(void) const;
};

#endif
