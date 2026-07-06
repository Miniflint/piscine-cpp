#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal *animal[100];

    for (int i = 0; i < 100; i++)
    {
        if (i < 50)
            animal[i] = new Dog("Dog" + i);
        else
            animal[i] = new Cat("Cat" + i);
    }
    animal[52]->setIdea("no clue");
    animal[52]->setIdea("no clue 2");
    animal[52]->setIdea("no clue 3");
    animal[52]->getIdeas();
    for (int i = 0; i < 100; i++)
    {
        delete animal[i];
    }
	return (0);
}