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
		bool isLeapYear(const std::string& date);
		bool isHeaderExist(const std::string& header);
		bool isValidValue(const std::string& date, const std::string& value);
		std::string findClosestDate(const std::string& date);
		bool processLine(const std::string& line);
    	bool validateInput(const std::string& date, const std::string& value);
    	void calculateAndPrintResult(const std::string& date, const std::string& value);
    	std::string trimRight(const std::string& s);
    	std::string trimLeft(const std::string& s);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		bool loadDatabase(const std::string& filename);
		bool processInputFile(const std::string& filename);
};

#endif