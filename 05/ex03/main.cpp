#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
// #include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void testBureaucrat()
{
    std::cout << "--- Testing Bureaucrat class ---" << std::endl;

    try
    {
        std::cout << "Creating a bureaucrat with grade 1 (highest):" << std::endl;
        Bureaucrat high("High Grade", 1);
        std::cout << high << std::endl;

        std::cout << "Trying to increment grade (should throw exception):" << std::endl;
        high.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    try
    {
        std::cout << "Creating a bureaucrat with grade 150 (lowest):" << std::endl;
        Bureaucrat low("Low Grade", 150);
        std::cout << low << std::endl;
        std::cout << "Trying to decrement grade (should throw exception):" << std::endl;
        low.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        std::cout << "Creating a bureaucrat with invalid grade 0:" << std::endl;
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        std::cout << "Creating a bureaucrat with invalid grade 151:" << std::endl;
        Bureaucrat invalid("Invalid", 151);
        std::cout << invalid << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "Creating a bureaucrat with grade 75:" << std::endl;
        Bureaucrat mid("Middle Grade", 75);
        std::cout << mid << std::endl;

        std::cout << "Incrementing grade:" << std::endl;
        mid.incrementGrade();
        std::cout << mid << std::endl;

        std::cout << "Decrementing grade twice:" << std::endl;
        mid.decrementGrade();
        mid.decrementGrade();
        std::cout << mid << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testShrubberyCreationForm()
{
    std::cout << "\n--- Testing ShrubberyCreationForm ---" << std::endl;
    try
    {
        ShrubberyCreationForm form("garden");
        std::cout << form << std::endl;

        Bureaucrat high("High Grade", 1);
        Bureaucrat mid("Mid Grade", 140);
        Bureaucrat low("Low Grade", 150);

        std::cout << "\nTesting form signing and execution:" << std::endl;
        
        // Low grade bureaucrat can't sign
        std::cout << "Low grade bureaucrat trying to sign (should fail):" << std::endl;
        low.signForm(form);
        
        // Mid grade bureaucrat can sign but can't execute
        std::cout << "\nMid grade bureaucrat signing:" << std::endl;
        mid.signForm(form);
        std::cout << form << std::endl;
        
        std::cout << "Mid grade bureaucrat trying to execute (should fail):" << std::endl;
        mid.executeForm(form);
        
        // High grade bureaucrat can execute
        std::cout << "\nHigh grade bureaucrat executing:" << std::endl;
        high.executeForm(form);

    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testRobotomyRequestForm()
{
    std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;

    try
    {
        RobotomyRequestForm form("Bender");
        std::cout << form << std::endl;

        Bureaucrat high("High Grade", 1);
        Bureaucrat mid("Mid Grade", 50);
        Bureaucrat low("Low Grade", 100);

        std::cout << "\nTesting form signing and execution:" << std::endl;
        
        // Low grade bureaucrat can't sign
        std::cout << "Low grade bureaucrat trying to sign (should fail):" << std::endl;
        low.signForm(form);
        
        // Mid grade bureaucrat can sign but can't execute
        std::cout << "\nMid grade bureaucrat signing:" << std::endl;
        mid.signForm(form);
        std::cout << form << std::endl;
        
        std::cout << "Mid grade bureaucrat trying to execute (should fail):" << std::endl;
        mid.executeForm(form);
        
        // High grade bureaucrat can execute
        std::cout << "\nHigh grade bureaucrat executing:" << std::endl;
        high.executeForm(form);

    } catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testPresidentialPardonForm()
{
    std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;

    try
    {
        PresidentialPardonForm form("Arthur Dent");
        std::cout << form << std::endl;

        Bureaucrat high("High Grade", 1);
        Bureaucrat mid("Mid Grade", 20);
        Bureaucrat low("Low Grade", 30);

        std::cout << "\nTesting form signing and execution:" << std::endl;
        
        // Low grade bureaucrat can't sign
        std::cout << "Low grade bureaucrat trying to sign (should fail):" << std::endl;
        low.signForm(form);
        
        // Mid grade bureaucrat can sign but can't execute
        std::cout << "\nMid grade bureaucrat signing:" << std::endl;
        mid.signForm(form);
        std::cout << form << std::endl;
        
        std::cout << "Mid grade bureaucrat trying to execute (should fail):" << std::endl;
        mid.executeForm(form);
        
        // High grade bureaucrat can execute
        std::cout << "\nHigh grade bureaucrat executing:" << std::endl;
        high.executeForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testIntern()
{
    std::cout << "\n--- Testing Intern class ---" << std::endl;

    Intern intern;
    Bureaucrat boss("Boss", 1);
    
    // Test valid form creation
    std::cout << "\nCreating a shrubbery creation form:" << std::endl;
    AForm* form1 = intern.makeForm("shrubbery creation", "home");
    if (form1)
    {
        std::cout << *form1 << std::endl;
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }
    
    std::cout << "\nCreating a robotomy request form:" << std::endl;
    AForm* form2 = intern.makeForm("robotomy request", "Bender");
    if (form2)
    {
        std::cout << *form2 << std::endl;
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }
    
    std::cout << "\nCreating a presidential pardon form:" << std::endl;
    AForm* form3 = intern.makeForm("presidential pardon", "Zaphod");
    if (form3)
    {
        std::cout << *form3 << std::endl;
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }
    
    // Test invalid form creation
    std::cout << "\nTrying to create an invalid form:" << std::endl;
    AForm* form4 = intern.makeForm("invalid form", "target");
    if (form4)
    {
        delete form4;
    }
}

int main()
{
    testBureaucrat();
    testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
    testIntern();
    return 0;
}