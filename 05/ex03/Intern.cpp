#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    (void)other; // Unused parameter
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other; // Unused parameter
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    // Define form types and their corresponding creation functions
    struct FormType
    {
        std::string name;
        FormCreator creator;
    };
    FormType formTypes[] =
    {
        {"shrubbery creation", &Intern::createShrubberyCreationForm},
        {"robotomy request", &Intern::createRobotomyRequestForm},
        {"presidential pardon", &Intern::createPresidentialPardonForm}
    };
    // Number of form types
    const int numFormTypes = sizeof(formTypes) / sizeof(formTypes[0]);
    // Find the requested form type
    for (int i = 0; i < numFormTypes; i++)
    {
        if (formName == formTypes[i].name) {
            AForm* form = (this->*(formTypes[i].creator))(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    
    // Form not found
    std::cout << "Intern cannot create form: " << formName << " (unknown form type)" << std::endl;
    return NULL;
}