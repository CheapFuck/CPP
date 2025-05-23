#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request Form", 72, 45), target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("Robotomy Request Form", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), target(other.target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    checkExecuteRequirements(executor);
    
    std::cout << "* Drilling noises *" << std::endl;
    
    std::srand(std::time(NULL));
    
    if (std::rand() % 2)
    {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy of " << target << " failed!" << std::endl;
    }
}
