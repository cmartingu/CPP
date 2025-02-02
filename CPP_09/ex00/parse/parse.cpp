#include "../exchange/BitcoinExchange.hpp"

std::ifstream	*parseFileName(void)
{
	std::string name = DATA_ROUTE;

	if (name.size() < 4 || name.substr(name.size() - 4) != ".csv")
		throw std::logic_error("Invalid file name: " + name);

	std::ifstream *file = new std::ifstream(name.c_str());
	if (!(*file).is_open())
		throw std::logic_error("Cannot open file " + name);

	return file;
}

bool	parseFirstLineData(std::string line)
{
	if (line != "date,exchange_rate")
		throw std::logic_error("Wrong line in data base: " + line);
	return true;
}

bool isValidDay(int day)
{
	if (day > 0 && day < 32)
		return true;
	return false;
}

bool isValidMonth(int month)
{
	if (month > 0 && month < 13)
		return true;
	return false;
}

bool	isValidYear(int year)
{
	if (year > 0)
		return true;
	return false;
}

bool parseDates(std::string date)
{
	if (!isValidYear(std::atoi((date.substr(0,4)).c_str())))
		return false;
	if (!isValidMonth(std::atoi((date.substr(5,2)).c_str())))
		return false;
	if (!isValidDay(std::atoi((date.substr(8,2)).c_str())))
		return false;
	return true;
}

bool	isValidDateFormat(const std::string &date)//formato de fecha válido
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i=0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!isdigit(date[i]))
			return false;
	}
	return parseDates(date);
}