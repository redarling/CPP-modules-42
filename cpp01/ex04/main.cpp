#include <iostream>
#include <fstream>
#include <string>

static std::string getReplacedLine(const std::string& line, const std::string& target, const std::string& replacement)
{
    size_t      pos = 0;
    size_t      prevPos = 0;
    std::string result;

    while ((pos = line.find(target, prevPos)) != std::string::npos)
    {
        result.append(line.substr(prevPos, pos - prevPos));
        result.append(replacement);
        prevPos = pos + target.length();
    }
    result.append(line.substr(prevPos));

    return (result);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
        return 1;
    }

    std::string     inputFileName = argv[1];
    std::string     s1 = argv[2];
    std::string     s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "The string to replace cannot be empty" << std::endl;
        return (1);
    }

    std::string     outputFileName = inputFileName + ".replace";
    std::string     line;
    std::ifstream   inputFile(inputFileName);

    if (!inputFile)
    {
        std::cerr << "Unable to open file for reading: "
                  << inputFileName << std::endl;
        return (1);
    }

    std::ofstream   outputFile(outputFileName);

    if (!outputFile)
    {
        std::cerr << "Unable to open file for writing: "
                  << outputFileName << std::endl;
        inputFile.close();
        return (1);
    }

    while (std::getline(inputFile, line))
    {
        line = getReplacedLine(line, s1, s2);
        outputFile << line << '\n';
    }

    inputFile.close();
    outputFile.close();

    return (0);
}
