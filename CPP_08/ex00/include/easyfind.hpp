#pragma once

#include <algorithm>
#include <exception>

class ValueNotFoundException: public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Value not found";
		}
};

template <typename T>
typename T::iterator	easyfind(T &container, int val)
{
	typename T::iterator it = std::find(container.begin(), container.end(), val);

	if (it == container.end())
		throw ValueNotFoundException();
	return (it);
}
