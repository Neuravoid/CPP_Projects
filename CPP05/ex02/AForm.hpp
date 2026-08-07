#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class AForm{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
        std::string target;
    public:

        class GradeException : public std::exception{
            private:
                const char* msg;
            public:
                GradeException(const char* msg);
                const char* what() const throw();
        };

        AForm();
        AForm(const std::string name, const int signGrade, const int execGrade, const std::string target);
        virtual ~AForm();
        AForm(const AForm& ref);
        AForm& operator=(const AForm& ref);


        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        const std::string getTarget() const;

        void beSigned(const Bureaucrat& ref);
        virtual void action() const = 0;
        void execute(const Bureaucrat& ref) const;



        
};

std::ostream& operator<<(std::ostream& out, AForm& ref);

#endif
