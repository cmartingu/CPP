#pragma once

# include <string>

template <typename I>
void	iter(I *str, size_t	len, void (*f)(I &))
{
	if (str == NULL || f == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		f(str[i]);
}