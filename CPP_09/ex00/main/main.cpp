#include "../exchange/BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Error: Remember to set 1 arguments:\n\tData base to evaluate" << std::endl;
		return 1;
	}
	try
	{
		BtcEx btc;
		doInput(btc, argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}