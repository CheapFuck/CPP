#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors and destructor
AForm::AForm() : name("Default Form"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) 
    : name(other.name), isSigned(other.isSigned), 
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        // Can't assign to const attributes
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm() {}

// Getters
std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

// Sign form
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

// Check execute requirements
void AForm::checkExecuteRequirements(Bureaucrat const & executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}

// Exception implementations
const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high! The highest grade is 1.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low! The lowest grade is 150.";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

// Insertion operator overload
std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form: " << form.getName() 
       << ", Sign Status: " << (form.getIsSigned() ? "Signed" : "Not signed")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}