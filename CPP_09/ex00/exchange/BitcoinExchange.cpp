#include "BitcoinExchange.hpp"
#include <iostream>
#include <iomanip>  // Para std::fixed y std::setprecision
#include <cstdlib>  // Para std::strtod
#include <string>

float	stringToFloat(std::string const &str)
{
    char* end;
    float value = std::strtof(str.c_str(), &end);

    // Verifica si no se pudo convertir ningún valor
    if (str.c_str() == end) {
        throw std::invalid_argument("Invalid float format: no conversion could be performed");
    }

    // Verifica si hay caracteres no numéricos después del número
    if (*end != '\0') {
        throw std::invalid_argument("Invalid float format: extra characters found");
    }

    return value;
}

BtcEx::BtcEx(void)
{
	std::ifstream   *file = parseFileName();
	std::string     line;

	std::getline(*file, line);
	parseFirstLineData(line);
	while (std::getline(*file, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			throw std::logic_error("Wrong line in data base: " + line);

		std::string date = line.substr(0, pos);
		if (!isValidDateFormat(date))
			throw std::logic_error("Wrong line in data base: " + line);

		float val;
		try
		{
			val = stringToFloat(line.substr(pos + 1));
			if (val < 0)
				throw std::logic_error("Wrong line in data base: " + line);
			this->setData(date, val);
			//std::cout << "date: " << date << ".\tprice: " << val << "." << std::endl;
		}
		catch(const std::exception& e)
		{
			if (&e == &e)
				throw std::logic_error("Wrong line in data base: " + line);
			throw std::logic_error("Wrong line in data base: " + line);
		}
	}
	(*file).close();
	delete file;
}

BtcEx::BtcEx(BtcEx const &copy)
{
	*this = copy;
}

BtcEx::~BtcEx(void)
{
}

BtcEx &BtcEx::operator=(BtcEx const &copy)
{
	if (this != &copy)
		this->data = copy.data;
	return *this;
}

void	BtcEx::setData(std::string Date, float price)
{
	this->data.insert(std::make_pair(Date, price));
}

float const &BtcEx::getPrice(std::string const &Date) const
{
	std::map<std::string, float>::const_iterator it = this->data.lower_bound(Date);

	if (it == this->data.begin() && it->first != Date)
		throw std::logic_error("Not a valid date: " + Date);
	
	if (it == this->data.end() || it->first != Date)
        --it;
	return it->second;
}