#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    
    std::string *stringPTR = &str;
    std::string &stringREF = str;


    std::cout << "Memory address of str:            " << std::right << std::setw(40) << &str       << std::endl;
    std::cout << "Memory address held by stringPTR: " << std::right << std::setw(40) << stringPTR  << std::endl;
    std::cout << "Memory address held by stringREF: " << std::right << std::setw(40) << &stringREF << std::endl;
	std::cout << std::endl;
    std::cout << "Value of str:                     "  << std::right << std::setw(40) << std::right << str << std::endl;
    std::cout << "Value pointed to by stringPTR:    " << std::right << std::setw(40) << std::right << *stringPTR << std::endl;
    std::cout << "Value referred to by stringREF:   " << std::right << std::setw(40) << std::right << stringREF << std::endl;

    return 0;
}
