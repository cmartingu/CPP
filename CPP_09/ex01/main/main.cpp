#include "../RevPolNot/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: remember to set only one argument" << std::endl;
        return 1;
    }

    RPN calc(argv[1]);
    return (calc.calculate());
}