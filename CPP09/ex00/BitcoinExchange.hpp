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
		bool isValidValue(const std::string& date, const std::string& value);
		std::string findClosestDate(const std::string& date);
		void processLine(const std::string& line);
    	bool validateInput(const std::string& date, const std::string& value);
    	void calculateAndPrintResult(const std::string& date, const std::string& value);
    	std::string trimRight(const std::string& s);
    	std::string trimLeft(const std::string& s);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		void loadDatabase(const std::string& filename);
		void processInputFile(const std::string& filename);

		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

};

#endif