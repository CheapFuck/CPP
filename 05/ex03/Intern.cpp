#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{}

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
    const int numFormTypes = sizeof(formTypes) / sizeof(formTypes[0]);
    for (int i = 0; i < numFormTypes; i++)
    {
        if (formName == formTypes[i].name)
        {
            AForm* form = (this->*(formTypes[i].creator))(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    
    std::cout << "Intern cannot create form: " << formName << " (unknown form type)" << std::endl;
    return NULL;
}
