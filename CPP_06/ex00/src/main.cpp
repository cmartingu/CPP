#include "../include/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Remember to set 1 argument" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
}

/*int main(void)
{
    ScalarConverter::convert("'a'");
    std::cout << std::endl;
    ScalarConverter::convert("42");
    std::cout << std::endl;
    ScalarConverter::convert("4.2f");
    std::cout << std::endl;
    ScalarConverter::convert("-inf");
    std::cout << std::endl;
    ScalarConverter::convert("nanf");
    return 0;
}*/
