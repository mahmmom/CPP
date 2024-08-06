#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	this->data = other.data;
	this->input = other.input;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::fillInput(std::string file)
{
	std::ifstream ifs(file);
	if (!ifs.is_open())
	{
		std::cerr << "Error: file not found" << std::endl;
		return;
	}
	std::string line;
	while (std::getline(ifs, line))
	{
		std::string name;
		double value;
		std::stringstream ss(line);
		ss >> name >> value;
		this->input[name] = value;
	}
	ifs.close();
}

void BitcoinExchange::fillData(std::string file)
{
	std::ifstream ifs(file);
	if (!ifs.is_open())
	{
		std::cerr << "Error: file not found" << std::endl;
		return;
	}
	if (ifs.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "Error: file is empty" << std::endl;
		return;
	}
	std::string line;
	while (std::getline(ifs, line))
	{
		// if(line.empty())
		// 	continue;
		// if(line.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
		// 	continue;
		// if(line.find_first_not_of("0123456789.") == std::string::npos)
		// 	continue;
		std::string name;
		double value;
		std::stringstream ss(line);
		ss >> name >> value;
		this->data[name] = value;
	}
	ifs.close();
}

void BitcoinExchange::printMap()
{
	for (std::map<std::string, double>::iterator it = this->data.begin(); it != this->data.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}

