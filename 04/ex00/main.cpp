#include "Animal.hpp"
#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    // Original tests
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    // Print the type and make sounds
    std::cout << j->getType() << " " << std::endl;  // Should print "Dog"
    std::cout << i->getType() << " " << std::endl;  // Should print "Cat"
    i->makeSound();  // Should print "Meow!"
    j->makeSound();  // Should print "Woof!"
    meta->makeSound(); // Should print "Animal sound!"
    
    // Clean up
    delete meta;
    delete j;
    delete i;

    // Additional tests using WrongAnimal and WrongCat
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongJ = new WrongCat();
    
    std::cout << wrongJ->getType() << " " << std::endl;  // Should print "WrongCat"
    wrongJ->makeSound();  // Should print "WrongAnimal sound!"
    wrongMeta->makeSound();  // Should print "WrongAnimal sound!"
    
    // Clean up for WrongAnimal
    delete wrongMeta;
    delete wrongJ;

    // Additional tests with multiple objects of the same class
    const Animal* a = new Dog();
    const Animal* b = new Dog();
    
    std::cout << a->getType() << " " << std::endl;  // Should print "Dog"
    a->makeSound();  // Should print "Woof!"
    
    std::cout << b->getType() << " " << std::endl;  // Should print "Dog"
    b->makeSound();  // Should print "Woof!"
    
    // Clean up Dog objects
    delete a;
    delete b;

    return 0;
}
