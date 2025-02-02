#pragma once

# include <iostream>
# include <cstdlib>
# include <stack>

class RPN
{
	private:
		RPN(void);
		std::stack<double> numbers;
		std::string input;

	public:
		//constructors
			RPN(std::string const &input);
			RPN(RPN const &copy);

		//destructors
			~RPN(void);

		//operators
			RPN &operator=(RPN const &copy);

		//public methods
			int calculate(void);
};