#pragma once

# include <iostream>
# include <deque>
# include <list>
# include <algorithm>
# include <ctime>
# include <iomanip>
# include <cstdlib>

class PmergeMe
{
	private:
			PmergeMe(void);

	public:
		//constructors
			PmergeMe(int argc, char **argv);
			PmergeMe(PmergeMe const &copy);
		
		//destructor
			~PmergeMe(void);

		//operators
			PmergeMe	&operator=(PmergeMe const &copy);

		//public methods
			static double	orderDeque(std::deque<int> &deq); //devuelve el tiempo que tarda en ordenarlo
			static double	orderList(std::list<int> &list); //devuelve el tiempo que tarda en ordenarlo

		//templates
			template <typename T>
			static void	printContainer(T const &container)
			{
				typename T::const_iterator it;
				for (it = container.begin(); it != container.end(); ++it)
					std::cout << *it << " ";
				std::cout << std::endl;
			}

		//exceptions
			class OnlyPositiveNumbersException: public std::exception
			{
				public:
					virtual const char *what() const throw()
					{
						return "The list must contain only integer and positive numbers";
					}
			};
};