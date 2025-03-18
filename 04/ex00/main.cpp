#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* i = new Dog();
    const Animal* j = new Cat();
    
    std::cout << i->getType() << " " << std::endl; //dog
    std::cout << j->getType() << " " << std::endl; //cat
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
    delete j;
    std::cout << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongJ = new WrongCat();

    std::cout << wrongJ->getType() << " " << std::endl;
    wrongJ->makeSound();
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongJ;
    std::cout << std::endl;

    const Animal* a = new Dog();
    const Animal* b = new Dog();

    std::cout << a->getType() << " " << std::endl;
    a->makeSound();
    std::cout << b->getType() << " " << std::endl;
    b->makeSound();
    delete a;
    delete b;

    return 0;
}
