#include "principal.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

void    Contact::save_data(std::string name, std::string l_name, std::string nnm, std::string nb, std::string ds)
{
	_name = name;
	_l_name = l_name;
	_nickname = nnm;
	_number = nb;
	_dark_secret = ds;
}

void	Contact::print_data(void)
{
	std::cout << "First name: " << this->_name << std::endl;
	std::cout << "Last name: " << this->_l_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_number << std::endl;
	std::cout << "Darkest secret: " << this->_dark_secret << std::endl;
}

std::string	Contact::get_first_name()
{
	return (_name);
}

std::string	Contact::get_last_name()
{
	return (_l_name);
}

std::string	Contact::get_nickname()
{
	return (_nickname);
}

std::string	Contact::get_phone_number()
{
	return (_number);
}

std::string	Contact::get_darkest_secret()
{
	return (_dark_secret);
}