#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade();  // Should succeed
        std::cout << b1 << std::endl;

        b1.incrementGrade();  // Should throw
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b2("Bob", 151);  // Invalid grade
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
