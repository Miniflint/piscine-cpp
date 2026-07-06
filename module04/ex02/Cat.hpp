#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;

	public:
		Cat(void);
        Cat(std::string type);
		Cat(Cat const &anim);
        Cat &operator=(Cat &anim);
		~Cat(void);
		virtual void makeSound(void) const;
		void	getIdeas(void);
};


#endif