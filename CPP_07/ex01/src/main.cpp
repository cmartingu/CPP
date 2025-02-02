#include "../include/iter.hpp"

#include <iostream>
#include <cctype>

void ft_tolower(char &arr)
{
	arr = std::tolower(static_cast<unsigned char>(arr));
}

void ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
}

void	ft_sum(int &nb)
{
	nb++;
}

int main()
{
	char a[] = {'A', 'B', 'C'};

	std::cout << "Original:" << std::endl <<
	"\ta[0]: " << a[0] << std::endl <<
	"\ta[1]: " << a[1] << std::endl <<
	"\ta[2]: " << a[2] << std::endl << std::endl;

	::iter(a, 3, ft_tolower);

	std::cout << "Changed:" << std::endl <<
	"\ta[0]: " << a[0] << std::endl <<
	"\ta[1]: " << a[1] << std::endl <<
	"\ta[2]: " << a[2] << std::endl << std::endl;

	::iter(a, 2, ft_toupper);

	std::cout << "Changed:" << std::endl <<
	"\ta[0]: " << a[0] << std::endl <<
	"\ta[1]: " << a[1] << std::endl <<
	"\ta[2]: " << a[2] << std::endl << std::endl;

	std::cout << "*********************************************************" << std::endl;
	
	int b[] = {1, 2, 3};

	std::cout << "Original:" << std::endl <<
	"\tb[0]: " << b[0] << std::endl <<
	"\tb[1]: " << b[1] << std::endl <<
	"\tb[2]: " << b[2] << std::endl << std::endl;

	::iter(b, 3, ft_sum);

	std::cout << "Changed:" << std::endl <<
	"\tb[0]: " << b[0] << std::endl <<
	"\tb[1]: " << b[1] << std::endl <<
	"\tb[2]: " << b[2] << std::endl << std::endl;

	::iter(b, 2, ft_sum);

	std::cout << "Changed:" << std::endl <<
	"\tb[0]: " << b[0] << std::endl <<
	"\tb[1]: " << b[1] << std::endl <<
	"\tb[2]: " << b[2] << std::endl << std::endl;
}