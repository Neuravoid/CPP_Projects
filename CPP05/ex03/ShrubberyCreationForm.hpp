#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:

		class FileException : public std::exception{
			const char* what() const throw();
		};

		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);
		ShrubberyCreationForm(const ShrubberyCreationForm& ref);
		void createTree(int n, char c, std::ofstream &ref) const;
		void action() const;
};

#endif
