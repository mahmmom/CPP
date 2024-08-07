#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

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
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value)
{
    char* end;
    double val = std::strtod(value.c_str(), &end);

    if (*end != '\0' || val < 0 || val > 1000)
		return false;
    return true;
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

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
	{
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
	{
        std::istringstream iss(line);
        std::string date;
        double rate;
        if (std::getline(iss, date, ',') && (iss >> rate))
		{
            exchangeRates[date] = rate;
        }
    }
    file.close();
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
	{
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
	{
        std::istringstream iss(line);
        std::string date, value;
        if (std::getline(iss, date, '|') && std::getline(iss, value))
		{
            date = date.substr(0, date.find_last_not_of(" \t") + 1);
            value = value.substr(value.find_first_not_of(" \t"));

            if (!isValidDate(date))
			{
                std::cout << "Error: bad input => " << date << std::endl;
            }
			else if (!isValidValue(value))
			{
                if (value[0] == '-')
				{
                    std::cout << "Error: not a positive number." << std::endl;
                }
				else
				{
                    std::cout << "Error: too large a number." << std::endl;
                }
            }
			else
			{
                std::string closestDate = findClosestDate(date);
                double rate = exchangeRates[closestDate];
                double amount = std::atof(value.c_str());
                double result = amount * rate;

                std::cout << date << " => " << value << " = " << result << std::endl;
            }
        }
		else
		{
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }
    file.close();
}