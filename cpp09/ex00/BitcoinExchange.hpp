#pragma once

# include <iostream>
# include <algorithm>
# include <map>
# include <string>
# include <fstream>
# include "Date.hpp"

const size_t    DATE_LENGTH = 10;
const double    MAX_AMOUNT = 1000.0;

class BitcoinExchange
{
    private:
        std::map<t_date, double>    _dataBase;
        const std::string           _data_csv;

        bool                fillDataBase(std::ifstream& dataFile);

        bool                processDataLine(const std::string& line);
        void                processInputLine(const std::string& line);
        double              getExchangeRateForDate(const t_date& date);

        bool                validateDate(const std::string& dateStr, t_date &date) const;
        bool                validateValue(const std::string& price, double& value) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange();
        BitcoinExchange&    operator=(const BitcoinExchange& other);

        void                getExchange(const std::string& fileName);
};