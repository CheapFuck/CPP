#include "Animal.hpp"
#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    // Test 1: Create Dog and Cat objects and delete them properly
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    // Call makeSound() to ensure polymorphism works
    j->makeSound();  // Expected: Woof!
    i->makeSound();  // Expected: Meow!
    
    // Test 2: Deleting the objects should call their destructors
    delete j; // No memory leak
    delete i; // No memory leak

    // Test 3: Create an array of Animals using polymorphism
    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();

    // Call makeSound() for each object in the array
    for (int i = 0; i < 2; ++i) {
        animals[i]->makeSound();
    }

    // Delete objects in the array to avoid memory leak
    for (int i = 0; i < 2; ++i) {
        delete animals[i];
    }

    // Test 4: Verify behavior when copying objects
    Dog dog1;
    dog1.makeSound(); // Woof!
    Dog dog2 = dog1;  // Using the copy constructor
    dog2.makeSound(); // Woof!

    // Test 5: Check assignment operator
    Cat cat1;
    cat1.makeSound(); // Meow!
    Cat cat2;
    cat2 = cat1;  // Using the copy assignment operator
    cat2.makeSound(); // Meow!

    return 0;
}
