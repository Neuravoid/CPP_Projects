#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& ref);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);
		void action() const;
};

#endif
