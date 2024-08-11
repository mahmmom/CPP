#include "BitcoinExchange.hpp"

/*=============== Constructors =======================*/
BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	exchangeRates = other.exchangeRates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	exchangeRates = other.exchangeRates;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}


/*=============== Class Functions =======================*/

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return false;
	}
	if(file.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "Error: empty file." << std::endl;
		return false;
	}

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
	{
        std::istringstream iss(line);
        std::string date;
        double rate;
        if (std::getline(iss, date, ',') && (iss >> rate))
            exchangeRates[date] = rate;
    }

    file.close();
    return true;
}

bool BitcoinExchange::processInputFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
		std::cerr << "Error: could not open file." << std::endl;
		return false;
	}

    std::string line;
    std::getline(file, line);
	if(!isHeaderExist(line))
	{
		std::cerr << "Error: header not found." << std::endl;
		return false;
	}
    if(file.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "Error: empty file." << std::endl;
		return false;
	}

    while (std::getline(file, line))
    {
        if(!processLine(line))
            return false;
    }
    file.close();
    return true;
}

bool BitcoinExchange::isHeaderExist(const std::string& header)
{
	if(header != "date | value")
		return false;
	return true;
}

bool BitcoinExchange::processLine(const std::string& line)
{
    std::istringstream iss(line);
    std::string date, value;

    if (!std::getline(iss, date, '|') || !std::getline(iss, value))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}

    date = trimRight(date);
    value = trimLeft(value);

    if(!validateInput(date, value))
		return false;
    calculateAndPrintResult(date, value);
    return true;
}

std::string BitcoinExchange::trimRight(const std::string& s)
{
    return s.substr(0, s.find_last_not_of(" \t") + 1);
}

std::string BitcoinExchange::trimLeft(const std::string& s)
{
    return s.substr(s.find_first_not_of(" \t"));
}

bool BitcoinExchange::validateInput(const std::string& date, const std::string& value)
{
    if (!isValidDate(date))
    {
		std::cout << "Error: invalid date => " << date << std::endl;
		return false;
	}
    if (!isValidValue(date, value))
		return false;
	return true;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.length() != 10)
		return false;
    if (date[4] != '-' || date[7] != '-')
		return false;
	
    int year, month, day;
    std::istringstream iss(date);
    char delimiter;

    iss >> year >> delimiter >> month >> delimiter >> day;
    if (year < 2009 || year > 2024|| month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if (month == 2 && day == 29 && !isLeapYear(date))
        return false;
    return true;
}

bool BitcoinExchange::isLeapYear(const std::string& date)
{
	int year = std::atoi(date.substr(0, 4).c_str());
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool BitcoinExchange::isValidValue(const std::string& date, const std::string& value)
{
    char* end;
    double val = std::strtod(value.c_str(), &end);

	if (*end != '\0') 
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (val < 0) 
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (val > std::numeric_limits<double>::max() || val > std::numeric_limits<int>::max() || val > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
    return true;
}

void BitcoinExchange::calculateAndPrintResult(const std::string& date, const std::string& value)
{
    std::string closestDate = findClosestDate(date);
    double rate = exchangeRates[closestDate];
    double amount = std::atof(value.c_str());
    double result = amount * rate;
    
    std::cout << date << " => " << value << " = " << result << std::endl;
}

std::string BitcoinExchange::findClosestDate(const std::string& date)
{
    std::map<std::string, double>::iterator it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.begin())
	return it->first;
    if (it == exchangeRates.end() || it->first != date)
		--it;
    return it->first;
}
