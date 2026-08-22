#include "RPN.hpp"

RPN::RPN(){
	this->stack.push(0);
}

RPN::~RPN(){
}




int RPN::getError()
{
	return this->error;
}

static bool isThereAnyDigit(char *str)
{
	int i = 0;
	int total = 0;
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			total++;
		}
		i++;
	}
	if (total == 0)
		return 0;
	else
		return total;	
}



RPN::RPN(std::string str){
	int i = 0;
	int calc = 0;
	this->error = 0;
	while (str[i] != '\0')
	{
		while(str[i] == ' ')
			i++;
		if(str[i]  == '\0')
			break;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i+1] >= '0' && str[i+1] <= '9')
			{
				std::cerr << "Please enter a number." << std::endl;
				this->error = 1;
				break;
			}
			else if (isThereAnyDigit(&str[i]) != 0)
			{
				int nbr = str[i] - '0';
				this->stack.push(nbr);
			}
	
		}
		else if(str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
		{
			if (this->stack.size() < 2)
			{	
				this->error = 1;
				std::cerr << "Error operator needs least 2 input." << std::endl;
				break;
			}
			else
			{
				int a = this->stack.top();
				this->stack.pop();
				int b = this->stack.top();
				this->stack.pop();
				if (str[i] == '+')
					calc = b + a;
				if (str[i] == '-')
					calc = b - a;
				if (str[i] == '*')
					calc = b * a;
				if (str[i] == '/')
				{
					if (a == 0)
					{
						std::cerr << "You can't a number divide to zero." << std::endl;
						this->error = 1;
						break;
					}
					
					calc = b / a;	
				}
				this->stack.push(calc);
			}
		}
		else
		{
			this->error = 1;
			std::cerr << "Error" << std::endl;
			break;
		}
		i++;
	}
	if (this->error == 0)
	{
		if (this->stack.size() == 1)
			std::cout << this->stack.top() << std::endl;
		else
		{
			std::cerr << "There is left numbers on stack" << std::endl;
			this->error = 1;
		}
	}
}


RPN& RPN::operator=(const RPN& ref){
	this->stack = ref.stack;
	return *this;
}

RPN::RPN(const RPN& ref){
	*this = ref;
}

std::stack<int>* RPN::returnStackPtr(){
	return(&this->stack);
}