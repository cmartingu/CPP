#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(std::string const &input): input(input)
{
}

RPN::RPN(RPN const &copy)
{
	*this = copy;
}

RPN::~RPN(void)
{
}

RPN &RPN::operator=(RPN const &copy)
{
	if (this != &copy)
	{
		this->input = copy.input;
		this->numbers = copy.numbers;
	}
	return *this;
}

int RPN::calculate(void)
{
	for (size_t i=0; this->input[i]; i++)
	{
		char c = this->input[i];

		if (c == ' ')
			continue ;
		else if (isdigit(c))
		{
			int nbr = atoi(&c);
			this->numbers.push(nbr);
		}
		else if (c == '+' && this->numbers.size() >= 2)
		{
			double b = this->numbers.top();
			this->numbers.pop();
			double a = numbers.top();
			this->numbers.pop();
			this->numbers.push(a + b);
		}
		else if (c == '-' && this->numbers.size() >= 2)
		{
			double b = this->numbers.top();
			this->numbers.pop();
			double a = numbers.top();
			this->numbers.pop();
			this->numbers.push(a - b);
		}
		else if (c == '*' && this->numbers.size() >= 2)
		{
			double b = this->numbers.top();
			this->numbers.pop();
			double a = numbers.top();
			this->numbers.pop();
			this->numbers.push(a * b);
		}
		else if (c == '/' && this->numbers.size() >= 2)
		{
			double b = this->numbers.top();
			this->numbers.pop();
			double a = this->numbers.top();
			this->numbers.pop();
			this->numbers.push(a / b);
		}
		else
		{
			std::cerr << "Error: Invalid input" << std::endl;
			return 1;
		}
	}

	if (this->numbers.size() == 1)
	{
		double result = this->numbers.top();
		this->numbers.pop();
		std::cout << "Result: " << result << std::endl;
	}
	else
	{
		std::cerr << "Error: Invalid input" << std::endl;
		return 1;
	}
	return 0;
}
