#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::deque<int>	deq;
	std::list<int>	list;

	srand(time(NULL));
	for (int i=1; i < argc; i++)
	{
		int val = atoi(argv[i]);
		if (val <=0)
			throw OnlyPositiveNumbersException();
		deq.push_back(val);
		list.push_back(val);
	}

	std::cout << "Before:\t";
	printContainer(deq);

	double timeDeque = orderDeque(deq);
	double timeList = orderList(list);

	std::cout << "After:\t";
	printContainer(deq);

	std::cout << std::fixed << std::setprecision(4);
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque container: " << timeDeque << " us" << std::endl;
    std::cout << "Time to process a range of " << list.size() << " elements with std::list container: " << timeList << " us" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy)
{
	if (this != &copy)
		return *this;
	return *this;
}

double	PmergeMe::orderDeque(std::deque<int> &deq)//falta por contar el tiempo que tarda
{
	std::deque<int>::iterator it;
	std::deque<int>::iterator itAux;
	clock_t	start = clock();

	for (it = deq.begin() + 1; it != deq.end(); ++it)
	{
		int tmp = *it;
		itAux = it;
		while (itAux != deq.begin() && *(itAux - 1) > tmp)
		{
			*itAux = *(itAux - 1);
			std::advance(itAux, -1);
		}
		*itAux = tmp;
	}
	clock_t end = clock();
	return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
}

double	PmergeMe::orderList(std::list<int> &list)//falta por contar el tiempo que tarda
{
	std::list<int>::iterator it;
	std::list<int>::iterator itAux;
	clock_t start = clock();

	for (it = list.begin(); it != list.end(); ++it)
	{
		int tmp = *it;
		itAux = it;
		std::list<int>::iterator prevIt = itAux;
		while (itAux != list.begin() && *(--prevIt) > tmp)
		{
			*itAux = *prevIt;
			itAux = prevIt;
		}
		*itAux = tmp;
	}
	clock_t end = clock();
	return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
}