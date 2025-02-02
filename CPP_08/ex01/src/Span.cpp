#include "../include/Span.hpp"

Span::Span(void): N(0)
{
	this->vec.reserve(0);
}

Span::Span(unsigned int const &nb): N(nb)
{
	this->vec.reserve(N); 
}

Span::Span(Span const &copy): vec(copy.vec), N(copy.getN())
{
}

Span::~Span(void)
{
}

Span &Span::operator=(Span const &copy)
{
	if (this != &copy)
	{
		this->N = copy.getN();
		this->vec = copy.vec;
	}
	return *this;
}

void	Span::addNumber(int const &nb)
{
	if (this->vec.size() >= N)
		throw CannotStoreMore();
	this->vec.push_back(nb);
}

int	Span::shortestSpan(void) const
{
	std::vector<int>	aux;

	aux = this->vec;
	if (this->getN() < 2)
		throw NotEnoughNumbers();
	
	std::sort(aux.begin(), aux.end()); //ordena el vector aux de menor a mayor
	
	int minSpan = aux[1] - aux[0];
	for (size_t i=2; i < aux.size(); i++)
	{
		int auxSpan = aux[i] - aux[i - 1];
		if (auxSpan < minSpan)
			minSpan = auxSpan;
	}
	return (minSpan);
}

int Span::longestSpan(void) const
{
	std::vector<int>	aux;

	aux = this->vec;
	if (this->getN() < 2)
		throw NotEnoughNumbers();
	std::sort(aux.begin(), aux.end()); //ordena el vector aux de menor a mayor
	return (aux.back() - aux.front()); //devuelve la diferencia entre el mayor y el menor
}

unsigned int const	&Span::getN(void) const
{
	return this->N;
}

const char *Span::CannotStoreMore::what() const throw()
{
	return "Cannot store more numbers";
}

const char	*Span::NotEnoughNumbers::what() const throw()
{
	return "Not enough numbers";
}

std::ostream &operator<<(std::ostream &str, Span const &src)
{
	str << "Span maximum storage: " << src.getN() << std::endl <<
	"Shortest span is " << src.shortestSpan() << std::endl <<
	"Longest span is " << src.longestSpan() << std::endl;
	return str;
}