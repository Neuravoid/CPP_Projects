#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Umut", 50);
		std::cout << b1;
		b1.incrementGrade();
		std::cout << b1;
		b1.decrementGrade();
		std::cout << b1;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooHigh("Invalid High", 0);
		std::cout << tooHigh;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooLow("Invalid Low", 200);
		std::cout << tooLow;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat topRank("Top", 1);
		std::cout << topRank;
		topRank.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bottomRank("Bottom", 150);
		std::cout << bottomRank;
		bottomRank.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
