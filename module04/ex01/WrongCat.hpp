#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal
{
	private:
		Brain	*_brain;

	public:
		WrongCat(void);
        WrongCat(std::string type);
		WrongCat(WrongCat const &anim);
        WrongCat &operator=(WrongCat &anim);
		~WrongCat(void);
		virtual void makeSound(void) const;
		void	getIdeas(void);
};


#endif