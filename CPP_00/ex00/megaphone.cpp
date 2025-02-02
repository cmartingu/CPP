/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-m <carlos-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:15:15 by carlos-m          #+#    #+#             */
/*   Updated: 2024/04/23 12:15:16 by carlos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	std::string final_arg;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc ; i++)
	{
		final_arg = argv[i];
		int	len = final_arg.length();
		for (int j = 0; j < len; j++)
		{
			std::cout << (char)(toupper(final_arg[j]));
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
