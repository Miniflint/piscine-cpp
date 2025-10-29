#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    private:
        Brain *_brain;

	public:
		Cat(void);
        Cat(std::string name);
		Cat(Cat const &anim);
        Cat &operator=(Cat &anim);
		~Cat(void);
        Brain *getBrain(void) const;
		virtual void makeSound(void) const;
};

#endif