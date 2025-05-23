#pragma once
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;
class Form
{
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    explicit Form(const std::string& name, int gradeToSign, int gradeToExecute);
    
    Form(const Form& other);
    Form& operator=(const Form& other);
    virtual ~Form();
    
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    
    void beSigned(const Bureaucrat& b);

    class GradeTooHighException : public std::exception
    {
    public:
        GradeTooHighException() noexcept = default;
        ~GradeTooHighException() noexcept override = default;
        const char* what() const noexcept override;
    };
    
    class GradeTooLowException : public std::exception
    {
    public:
        GradeTooLowException() noexcept = default;
        ~GradeTooLowException() noexcept override = default;
        const char* what() const noexcept override;
    };
};

std::ostream& operator<<(std::ostream& os, const Form& f);


