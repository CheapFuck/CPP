#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* i = new Dog();
    const Animal* j = new Cat();
    
    i->makeSound();
    j->makeSound();

    delete i;
    delete j;

    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();

    for (int i = 0; i < 2; ++i)
    {
        animals[i]->makeSound();
    }

    for (int i = 0; i < 2; ++i)
    {
        delete animals[i];
    }
    Dog dog1;
    dog1.makeSound();
    Dog dog2 = dog1;
    dog2.makeSound();

    Cat cat1;
    cat1.makeSound();

    Cat cat2;
    cat2 = cat1;
    cat2.makeSound();

    std::cout << std::endl;
    std::cout << "type of dog1: " << dog1.getType() << std::endl;
    std::cout << "type of dog2: " << dog2.getType() << std::endl;
    if (dog1.getType() == dog2.getType())
    {
        std::cout << "Dog deep copy: Passed (same value for type)" << std::endl;
    } else
    {
        std::cout << "Dog deep copy: Failed (different value for type)" << std::endl;
    }
    std::cout << std::endl;
    std::cout << &dog1.getType() << std::endl;
    std::cout << &dog2.getType() << std::endl;
    if (&dog1.getType() != &dog2.getType())
    {
        std::cout << "Dog deep copy: Passed (different memory addresses for type)" << std::endl;
    } else
    {
        std::cout << "Dog deep copy: Failed (same memory addresses for type)" << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
