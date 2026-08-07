#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();
        };

        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw();
        };

        class AlreadySignedException : public std::exception{
            public:
                const char* what() const throw();
        };

        Form();
        Form(const std::string name, const int signGrade, const int execGrade);
        ~Form();
        Form(const Form& ref);
        Form& operator=(const Form& ref);


        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;


        void beSigned(const Bureaucrat& ref);
};

std::ostream& operator<<(std::ostream& out, Form& ref);

#endif