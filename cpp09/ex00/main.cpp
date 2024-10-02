#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: ./btc <filename>" << std::endl;
        return (1);
    }

    BitcoinExchange btc;
    btc.getExchange(argv[1]);
    
    return (0);
}