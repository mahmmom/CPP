#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>


class BitcoinExchange
{
	private:
		std::map<std::string, double> data;
		std::map<std::string, size_t> input;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void fillInput(std::string file);
		void fillData(std::string file);
		void printMap();


};



#endif