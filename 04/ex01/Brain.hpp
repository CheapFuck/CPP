#pragma once

#include <cstring>
#include <iostream>

class Brain
{
protected:
    std::string ideas[100];
public:
    // Default constructor
    Brain();
    // Cat(const std::string& value);
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();


};
