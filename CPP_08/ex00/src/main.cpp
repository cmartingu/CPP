#include "../include/easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>

int	main()
{
	std::set<int>		set;
	std::list<int>		list;
	std::deque<int>		deque;
	std::vector<int>	vector;

	for (int i = 0; i < 10; i++)
	{
		set.insert(i);
		list.push_back(i);
		deque.push_front(i);
		vector.push_back(i);
	}

	// Testing with set 
	std::cout << "**********Testing easyfind with Set**********\n\nSet:";
	for (std::set<int>::iterator it = set.begin(); it != set.end(); it++)
		std::cout << ' ' << *it;

	std::cout << std::endl;
	try
	{
		std::cout << "Looking for: 10" << std::endl;
		std::set<int>::iterator set_it = easyfind(set, 10);
		std::cout << "\nFound:  " << *set_it << std::endl;
	}
	catch(const ValueNotFoundException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	// Testing with list 
	std::cout << "**********Testing easyfind with List**********\n\nList:";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	try
	{
		std::cout << "Looking for: 1" << std::endl;
		std::list<int>::iterator list_it = easyfind(list, 1);
		std::cout << "\nFound:  " << *list_it << std::endl;
	}
	catch(const ValueNotFoundException& e)
	{
		std::cerr << "Error: "<< e.what() << std::endl;
	}

	// Testing with deque 
	std::cout << "**********Testing easyfind with Deque**********\n\nDeque:";
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	try
	{
		std::cout << "Looking for: 2" << std::endl;
		std::deque<int>::iterator deque_it = easyfind(deque, 2);
		std::cout << "\nFound: " << *deque_it << std::endl;
	}
	catch(const ValueNotFoundException& e)
	{
		std::cerr << "Error: "<< e.what() << std::endl;
	}

	// Testing with vector 
	std::cout << "**********Testing easyfind with Vector**********\n\nVector:";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	try
	{
		std::cout << "Looking for: 3" << std::endl;
		std::vector<int>::iterator vector_it = easyfind(vector, 3);
		std::cout << "\nFound: " << *vector_it << std::endl;
	}
	catch(const ValueNotFoundException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}