#ifndef BUREAUCRAT.HPP
#define BUREAUCRAT.HPP

#include <iostream>
#include <exception>

class Bureaucrat{
	private:
		std::string name;
		int grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &var);
		Bureaucrat& const operator=(Bureaucrat &var);

		class GradeTooHighException: std::exception{
			public:
				virtual const char* what() const throw() {
					return ("Grade is too high!");
				}
		}; 

		class GradeTooLowException: std::exception{
			public:
				virtual const char* what() const throw() {
					return ("Grade is too low!");
				}
		};

		std::string getName();

		int getGrade();

		void operator<<(const Bureaucrat &var);

};

#endif