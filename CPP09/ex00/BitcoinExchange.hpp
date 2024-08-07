#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <limits>

class BitcoinExchange
{
private:
    std::map<std::string, double> exchangeRates;
    bool isValidDate(const std::string& date);
    bool isValidValue(const std::string& value);
    std::string findClosestDate(const std::string& date);

public:
    BitcoinExchange();
    ~BitcoinExchange();

    void loadDatabase(const std::string& filename);
    void processInputFile(const std::string& filename);
};

#endif