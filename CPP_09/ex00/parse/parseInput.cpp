#include "../exchange/BitcoinExchange.hpp"

static void	parseFirstLineInput(std::string line)
{
	if (line != "date | value")
		throw std::logic_error("Wrong header in input data: " + line);
}

void cutSpaces(std::string *date)
{
	size_t pos = (*date).find(' ');
	if (pos == std::string::npos)
		return ;
	std::string aux = (*date).substr(pos);
	for (int i=0; aux[i] != '\0';i++)
	{
		if (aux[i] != ' ')
			throw std::logic_error("Wrong date in input data base: " + *date);
	}
	*date = (*date).substr(0, pos);
}

void cutValueSpaces(std::string *date, int i)
{
	size_t pos = (*date).find(' ', i);
	if (pos == std::string::npos)
	{
		(*date = (*date).substr(i));
		return ;
	}
	std::string aux = (*date).substr(pos);
	int j = 0;
	while (aux[j] != '\0')
	{
		if (aux[j] != ' ')
			throw std::logic_error("Wrong value in input data base: " + *date);
		j++;
	}
	*date = (*date).substr(i, pos - 1);
}

float	parseValue(std::string line)
{
	int i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			break ;
		i++;
	}//cuando salga de aqui me salté los espacios
	if (line[i] == '\0')
		throw std::logic_error("No value in input data base");
	cutValueSpaces(&line, i);
	i = 0;
	int countComas = 0;
	while (line[i])
	{
		if (line[i] == '-')
			throw std::logic_error("Negative value in input data base: " + line.substr(0));
		
		if (line[i] == '.')
		{
			if (countComas > 0)
				throw std::logic_error("Wrong value in input data base: " + line.substr(0));
			countComas++;
			if (i != 0 && line[i + 1] != '\0')//puedo hacer comprobacion
			{
				if (!isdigit(line[i - 1]) || !isdigit(line[i + 1]))
					throw std::logic_error("Wrong value in input data base: " + line.substr(0));
			}
			else
				throw std::logic_error("Wrong value in input data base: " + line.substr(0));
		}
		else if (!isdigit(line[i]))
			throw std::logic_error("Wrong value in input data base: " + line.substr(0));
		i++;
	}
	return std::atof((line.substr(0)).c_str());
}

// Función auxiliar para contar los decimales en printDateValue
static int	countDecimals(float num)
{
	int decimalPlaces = 0;
	while (std::fabs(num - static_cast<int>(num)) > 0.000001 && decimalPlaces < 6) // máximo 6 decimales
	{
		num *= 10;
		decimalPlaces++;
	}
	return decimalPlaces;
}

static void	printDateValue(BtcEx const &btc, float const &val, std::string const &date)
{
	float finalValue = btc.getPrice(date);
	float result = finalValue * val;

	int decimals = countDecimals(result);
	int decimalsVal = countDecimals(val);

	std::cout << date << " => ";
	std::cout << std::fixed << std::setprecision(decimalsVal) << val << " = ";
	std::cout << std::fixed << std::setprecision(decimals) << result << std::endl;
}

void	doInput(BtcEx const &btc, std::string nameFile)
{
	std::ifstream file(nameFile.c_str());
	if (!file.is_open())
		throw std::logic_error("Cannot open input file " + nameFile);

	std::string line;
	std::getline(file, line);
	parseFirstLineInput(line);

	while (std::getline(file, line))
	{
		try
		{
			size_t pos = line.find('|');
			if (pos == std::string::npos)
				throw std::logic_error("Wrong line in input data base: " + line);

			std::string date(line.substr(0,pos));
			cutSpaces(&date);
			if (!isValidDateFormat(date))
				throw std::logic_error("Wrong date in input data base: " + date);
			std::string value(line.substr(pos + 1));
			if (value[0] == '\0')
				throw std::logic_error("Wrong line in input data base: " + line);
			float val = parseValue(value);
			if (val > 1000)
				throw std::logic_error("Too large number in input data base: " + value);
			printDateValue(btc, val, date);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: "<< e.what() << std::endl;
		}
	}
	file.close();
}