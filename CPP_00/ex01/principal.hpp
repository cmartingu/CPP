#ifndef PRINCIPAL_HPP
# define PRINCIPAL_HPP

# include <iostream>
# include <iomanip>

class Contact
{
    private:
	    std::string _name;
	    std::string _l_name;
	    std::string _nickname;
	    std::string _number;
	    std::string _dark_secret;
    public:
	    Contact();
	    ~Contact();
	    void    save_data(std::string name, std::string l_name, std::string nnm, std::string nb, std::string ds);
	    void    print_data(void);
	    std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		std::string	get_phone_number();
		std::string	get_darkest_secret();
};

class PhoneBook
{
    public:
	    PhoneBook();
	    ~PhoneBook();
	    void    create_ctct(int i, std::string f, std::string l, std::string n, std::string ph, std::string d);
	    Contact get_contact(int i);
	    std::string	get_first_name(int i);
	    std::string	get_last_name(int i);
	    std::string	get_nickname(int i);
	    std::string	get_phone_number(int i);
	    std::string	get_darkest_secret(int i);
	private:
		Contact	phonebook[8];
};

#endif