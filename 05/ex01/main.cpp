#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "\n=== " <<  "Test 1: Valid Bureaucrat signs a valid Form" << " ===\n";
    try
    {
        Bureaucrat b1("Alice", 50);
        Form f1("FormA", 60, 70);
        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;

        b1.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== " <<  "Test 2: Low-grade Bureaucrat cannot sign Form" << " ===\n";
    try
    {
        Bureaucrat b2("Bob", 100);
        Form f2("SecretForm", 50, 60);

        b2.signForm(f2);
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== " <<  "Test 3: Create Form with grade too high (0)" << " ===\n";
    try
    {
        Form f3("BadForm", 0, 10);
    }
    catch (std::exception& e)
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== " <<  "Test 4: Create Form with grade too low (151)" << " ===\n";
    try
    {
        Form f4("AnotherBadForm", 151, 150);
    }
    catch (std::exception& e)
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== " <<  "Test 5: Bureaucrat increment beyond grade 1" << " ===\n";
    try
    {
        Bureaucrat b3("Carol", 1);
        b3.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== " <<  "Test 6: Bureaucrat decrement below grade 150" << " ===\n";
    try
    {
        Bureaucrat b4("Dave", 150);
        b4.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }
    return 0;
}
