#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
    delete j;
    std::cout << std::endl;


    const WrongAnimal* wrongmeta = new WrongAnimal();
    // const WrongAnimal* b = new Dog();
    const WrongAnimal* a = new WrongCat();
    
    // std::cout << b->getType() << " " << std::endl;
    std::cout << a->getType() << " " << std::endl;
    a->makeSound(); //will output the wronganimal sound!
    // b->makeSound();
    wrongmeta->makeSound();

    delete wrongmeta;
    delete a;
    // delete b;
    std::cout << std::endl;

    return 0;
}
