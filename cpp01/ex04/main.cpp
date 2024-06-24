#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return (1);
    }
    
    std::ifstream   inputFile(argv[1]);
    std::ofstream   outputFile(std::strcat(argv[1], ".replace"));
    std::string     line;

    if (!inputFile)
    {
        std::cerr << "Unable to open a file for reading" << std::endl;
        return (1);
    }
    if (!outputFile)
    {
        std::cerr << "Unable to open a file for writing" << std::endl;
        inputFile.close();
        return (1);
    }

    while (std::getline(inputFile, line))
    {
        std::cout << line << std::endl;
    }

    inputFile.close();
    outputFile.close();
}