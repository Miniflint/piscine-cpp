#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "==================================================================" << std::endl;
	Animal* meta = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound();
    delete i;
    delete j;
    std::cout << "==================================================================" << std::endl;

    meta = new Animal("test1");
	j = new Dog("test2");
	i = new Cat("test3");
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound();
    delete i;
    delete j;
    std::cout << "==================================================================" << std::endl;

	j = new Dog("testheh");
	i = j;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the dog sound!
    delete j;
    std::cout << "==================================================================" << std::endl;


	return 0;
}