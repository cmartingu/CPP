#include "../include/Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	Span	sp(5);
	int		n;

	srand(time(NULL));
	std::cout << "Adding some numbers to span\n" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		n = rand() % 100;
		std::cout << "Adding the number " << n << " to teh span" << std::endl;
		sp.addNumber(n);
	}

	std::cout << "\n" << sp << std::endl;
	std::cout << "\nLet's try adding more that span can handle..." << std::endl;
	try
	{
		sp.addNumber(4);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " <<e.what() << std::endl;
	}


	std::cout << "\nLet's create a span of 42000\nAdding elements..." << std::endl;
	Span	sp1(42000);

	for (int i = 0; i < 42000; i++)
	{
		if (i % 2)
			n = rand() % 10000;
		else
			n = (rand() % 10000) * (-1);
		sp1.addNumber(n);
	}
	std::cout << "\n" << sp1 << std::endl;

	return (0);
}