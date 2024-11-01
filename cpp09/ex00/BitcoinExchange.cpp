#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _dataBase(), _data_csv("data.csv")
{
    std::ifstream    dataFile(this->_data_csv.c_str());

    if (!dataFile)
    {
        std::cerr << "Error: could not open file: "
                  << this->_data_csv << std::endl;
        return ;
    }

    if (!this->fillDataBase(dataFile))
    {
        dataFile.close();
        this->_dataBase.clear();
        return ;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
                                    : _dataBase(other._dataBase),
                                      _data_csv(other._data_csv) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        this->_dataBase.clear();
        this->_dataBase = other._dataBase;
    }

    return (*this);
}

bool    BitcoinExchange::validateDate(const std::string& dateStr, t_date &date) const
{
    if (dateStr.empty() || dateStr.size() != DATE_LENGTH)
        return (false);
    
    for (size_t i = 0; i < DATE_LENGTH; ++i)
    {
        if (i == 4 || i == 7)
        {
            if (dateStr[i] != '-')
                return (false);
        }
        else if (!std::isdigit(dateStr[i]))
            return (false);
    }

    date.year = std::strtol((dateStr.substr(0, 4)).c_str(), NULL, 10);
    date.month = std::strtol((dateStr.substr(5, 2)).c_str(), NULL, 10);
    date.day = std::strtol((dateStr.substr(8, 2)).c_str(), NULL, 10);

    if (date.year < 2009 || date.month < 1 || date.month > 12 || date.day < 1 || date.day > 31)
        return (false);
    
    if (date.month == 2) 
    {
        bool isLeapYear = (date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0);

        if (isLeapYear) 
        {
            if (date.day > 29)
                return (false);
        } 
        else 
        {
            if (date.day > 28)
                return (false);
        }
    }
    else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
    {
        if (date.day > 30)
            return (false);
    }
    
    return (true);
}

bool    BitcoinExchange::validateValue(const std::string& valueStr, double& value) const
{
    bool    dotExists = false;

    if (valueStr.empty())
        return (false);

    for (size_t i = 0; i < valueStr.size(); ++i)
    {
        if (valueStr[i] == '.')
        {
            if (dotExists)
                return (false);
            dotExists = true;
        }
        else if (!std::isdigit(valueStr[i]))
            return (false);
    }
    
    value = std::strtod(valueStr.c_str(), NULL);
    
    if (value < 0)
        return (false);
    
    return (true);
}

bool    BitcoinExchange::processDataLine(const std::string& line)
{
    t_date      date;
    std::string dateStr;
     
    if (!line.find(',') || line.find(',') == 0 || line.find(',') == line.size() - 1)
        return (false);

    dateStr = line.substr(0, line.find(','));
    
    if (!this->validateDate(dateStr, date))
    {
        std::cerr << "Invalid date" << std::endl;
        return (false);
    }

    std::string valueStr = line.substr(line.find(',') + 1);
    double      price;
    
    if (!this->validateValue(valueStr, price))
        return (false);

    if (this->_dataBase.find(date) != this->_dataBase.end())
    {
        std::cerr << "Error: duplicate date" << std::endl;
        return (false);
    }
    
    this->_dataBase[date] = price;
    return (true);
}

bool    BitcoinExchange::fillDataBase(std::ifstream& dataFile)
{
    std::string     line;
    bool            dataExists = false;

    std::getline(dataFile, line);
    if (line.empty() || !line.compare("date,exchange_rate\n")) 
    {
        std::cerr << "Error: data file is empty or wrong header" << std::endl;
        return (false);
    }

    while (std::getline(dataFile, line))
    {
        if (!dataExists)
            dataExists = true;
        if (!processDataLine(line))
        {
            std::cerr << "Parsing error in data.csv line: " << line << std::endl;
            std::cerr << "Expected: <YYYY-MM-DD,value>" << std::endl;
            std::cerr << "Please note, that a date must be valid and a value should be above zero" << std::endl;
            return (false);
        }
    }

    if (!dataExists)
    {
        std::cerr << "Error: data file is empty" << std::endl;
        return (false);
    }

    return (true);
}

double  BitcoinExchange::getExchangeRateForDate(const t_date& date)
{
    std::map<t_date, double>::const_iterator it = this->_dataBase.lower_bound(date);

    if (it != _dataBase.end() && it->first == date)
    {
        return (it->second);
    }

    if (it == this->_dataBase.begin())
    {
        std::cerr << "Error: not possible to proccess date => "
                  << date.year << "-" << date.month << "-" << date.day << std::endl;
        return (-1);
    }

    --it;
    return (it->second);
}

void    BitcoinExchange::processInputLine(const std::string& line)
{
    t_date      date;
    std::string dateStr;
     
    std::size_t pos = line.find(" | ");
    if (pos == std::string::npos || pos == 0 || pos == line.size() - 3)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }

    dateStr = line.substr(0, pos);
    if (!this->validateDate(dateStr, date))
    {
        std::cerr << "Error: invalid date => " << dateStr << std::endl;
        return ;
    }

    std::string amountStr = line.substr(pos + 3);
    double      amount;
    
    if (!this->validateValue(amountStr, amount))
    {
        std::cerr << "Error: invalid or not positive amount => " << amountStr << std::endl;
        return ;
    } 

    if (amount > MAX_AMOUNT)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return ;
    }

    double  exchangeRate = getExchangeRateForDate(date);
    if (exchangeRate != -1)
    {
        double  result = amount * exchangeRate;

        std::cout << date.year << "-" << date.month << "-" 
                  << date.day << " => " << amount << " = " << result << std::endl;
    }
}

void    BitcoinExchange::getExchange(const std::string& fileName)
{
    if (fileName.empty())
    {
        std::cerr << "Error: file name is empty" << std::endl;
        return ;
    }

    if (this->_dataBase.empty())
    {
        std::cerr << "Error: data base is empty" << std::endl;
        return ;
    }

    std::ifstream    inputFile(fileName.c_str());

    if (!inputFile)
    {
        std::cerr << "Error: could not open file: " << fileName << std::endl;
        return ;
    }

    std::string     line;
    bool            dataExists = false;

    std::getline(inputFile, line);
    if (line.empty() || !line.compare("date | value\n")) 
    {
        std::cerr << "Error: input file is empty or wrong header" << std::endl;
        inputFile.close();
        return ;
    }

    while (std::getline(inputFile, line))
    {
        if(!dataExists)
            dataExists = true;
        processInputLine(line);
    }

    if (!dataExists)
        std::cerr << "Error: no data in input file" << std::endl;

    inputFile.close();
}