#pragma once
#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal
{
private:
    Brain* brain;
public:
    // Default constructor
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat() override;

    void makeSound() const override;

};
