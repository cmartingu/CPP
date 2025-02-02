#include "../include/Base.hpp"
#include <ctime>

Base *generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL))); //establece la semilla del generador de números aleatorios

	int randNum = std::rand() % 3;
	switch (randNum)
	{
		case 0:
			return new A();
			break ;
		case 1:
			return new B();
			break ;
		case 2:
			return new C();
			break ;
		default:
			perror("Error, something went wrong with the random generator\n");
			return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "This is A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "This is B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "This is C" << std::endl;
	else
		std::cout << "This is uknown" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "This is A" << std::endl;
	}
	catch (std::bad_cast &)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "This is B" << std::endl;
		}
		catch(const std::bad_cast &)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "This is C" << std::endl;
			}
			catch(const std::bad_cast &)
			{
				std::cout << "This is uknown" << std::endl;
			}
			
		}
	}
}

int main(void)
{
	Base* basePtr = generate();
	if (basePtr)
	{
		identify(basePtr);
		identify(*basePtr);
		delete basePtr;
	}
	return 0;
}