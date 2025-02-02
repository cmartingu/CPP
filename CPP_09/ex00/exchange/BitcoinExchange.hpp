#pragma once

# include <iostream>
# include <fstream>
# include <sstream>
# include <exception>
# include <map>
# include <cstdlib>
# include <string>
# include <iomanip>  // Para std::fixed y std::setprecision
# include <cmath>

# define DATA_ROUTE "data/data.csv"

class BtcEx
{
	private:
		std::map <std::string, float> data;

	public:
		//constructors
			BtcEx(void);
			BtcEx(BtcEx const &copy);

		//destructor
			~BtcEx(void);

		//operators
			BtcEx &operator=(BtcEx const &copy);

		//public methods
			void	setData(std::string Date, float price);

		//getters
			float const &getPrice(std::string const &Date) const;
};

//parse
std::ifstream	*parseFileName(void);
bool			parseFirstLineData(std::string line);
bool			isValidDateFormat(const std::string &date);

//input
void	doInput(BtcEx const &btc, std::string nameFile);