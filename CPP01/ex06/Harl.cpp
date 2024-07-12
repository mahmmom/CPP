#include "Harl.hpp"

Harl::Harl()
{
	levels[0] =  "debug";
	levels[1] =  "info";
	levels[2] =  "warning";
	levels[3] =  "error";
}

Harl::~Harl(){}

int	Harl::levFinder(std::string level)
{
    for (int i = 0; i < 4; ++i)
	{
        if (levels[i] == level)
            return(i);
    }
	return(4);
}

void	Harl::complain(std::string lev)
{
	int level = levFinder(lev);
	switch (level)
	{
	case 0:
		debug();
		info();
		warning();
		error();
		break;
	case 1:
		info();
		warning();
		error();
		break;
	case 2:
		warning();
		error();
		break;
	case 3:
		error();
		break;
	default:
    	std::cout << "Level not found" << std::endl;
		break;
	}
}


void Harl::debug()
{
    std::cout << "Debug: I love having extra Wagu for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "Info: I cannot believe adding extra Wagu costs more money. You didn't put enough Wagu in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "Warning: I think I deserve to have some extra Wagu for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "Error: This is unacceptable! I want to speak to the manager now." << std::endl;
}
