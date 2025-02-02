#include "../MergeClass/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cerr << "Error: You must provide a sequence of positive numbers" << std::endl;
		return (1);
	}

	try
	{
		PmergeMe pmergeMe(argc, argv);
		(void)pmergeMe;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}