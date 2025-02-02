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

#include "principal.hpp"

void	add_contact(PhoneBook *phonebook, int pos)
{
	std::string	name;
	std::string	l_name;
	std::string	nickname;
	std::string	number;
	std::string	dark_secret;

	std::cout << "Enter first name:\n";
	std::getline(std::cin, name);
	if (std::cin.eof())
		return ;
	std::cout << "Enter the last name\n";
	std::getline(std::cin, l_name);
	if (std::cin.eof())
		return ;
	std::cout << "Enter the nickname\n";
	std::getline(std::cin, nickname);
	if (std::cin.eof())
		return ;
	std::cout << "Enter the number\n";
	std::getline(std::cin, number);
	if (std::cin.eof())
		return ;
	std::cout << "Enter the darkest secret\n";
	std::getline(std::cin, dark_secret);
	if (std::cin.eof())
		return ;
	(*phonebook).create_ctct(pos, name, l_name, nickname, number, dark_secret);
	std::cout << "Contacto añadido correctamente\n";
}

void	search_ctct(PhoneBook *phonebook, int pos)
{
	std::string	name;
	std::string	l_name;
	std::string	nickname;
	std::string index;

	std::cout << std::endl;
	std::cout << std::setw(10) << "ind" << "|" << std::setw(10) << "First name" << "|" <<std::setw(10) << "Last name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 1; i < pos + 1; i++)
	{
		if (i > 8)
			break ;
		name = (*phonebook).get_first_name(i - 1);
		l_name = (*phonebook).get_last_name(i - 1);
		nickname = (*phonebook).get_nickname(i - 1);
		if (name.length() >= 10)
		{
			name.resize(9);
			name.resize(10, '.');
		}
		if (l_name.length() >= 10)
		{
			l_name.resize(9);
			l_name.resize(10, '.');
		}
		if (nickname.length() >= 10)
		{
			nickname.resize(9);
			nickname.resize(10, '.');
		}
		std::cout << std::setw(10) << i << "|" << std::setw(10) << name << "|" << std::setw(10) << l_name << "|" << std::setw(10) << nickname << "|" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Please enter the contact's index to see more details:\n> ";
	std::getline(std::cin, index);
	if (std::cin.eof())
		return ;
	if (index[0] <= pos + '0')
		std::cout << "POCILGON" << std::endl;
	if (index.length() == 1 && index[0] > '0' && index[0] <= pos + '0')
		(*phonebook).get_contact(index[0] - '0' - 1).print_data();
	else
		std::cout << "Wrong index" << "\n> ";
}

int main(void)
{
	std::string		read_line;
	PhoneBook		phonebook;
	int				contact_count;

	contact_count = 0;
	while (read_line != "EXIT")
	{
		std::cout << "What do you want to do (SEARCH / ADD / EXIT)?\n";
		std::getline(std::cin, read_line);
		if (std::cin.eof())
			return (0);
		else if (read_line == "ADD")
		{
			if (contact_count >= 8)
				std::cout << "You can only add 8 contacts" << std::endl;
			add_contact(&phonebook, contact_count % 8);
			contact_count++;
		}
		else if (read_line == "SEARCH")
		{
			search_ctct(&phonebook, contact_count);
		}
		else
			std::cout << "Remember that you can only ADD, SEARCH or EXIT\n";
	}
	return (0);
}