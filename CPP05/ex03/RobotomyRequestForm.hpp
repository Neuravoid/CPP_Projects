#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);
		RobotomyRequestForm(const RobotomyRequestForm& ref);
		void action() const;
};

#endif
