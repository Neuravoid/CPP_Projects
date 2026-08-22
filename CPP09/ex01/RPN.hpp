#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <string>

class RPN{
	private:
		std::stack<int>stack;
		int error;
	public:
		RPN();
		RPN(std::string str);
		~RPN();
		RPN(const RPN& ref);
		RPN& operator=(const RPN& ref);
		std::stack<int>* returnStackPtr();
		int getError();
		
};


#endif