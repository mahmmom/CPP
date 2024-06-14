#include "Harl.hpp"

Harl::Harl()
{
	levels[0] =  "debug";
	levels[1] =  "info";
	levels[2] =  "warning";
	levels[3] =  "error";
}

Harl::~Harl(){}

void	Harl::complain(std::string level)
{
	levFunc[0] = &Harl::debug;
	levFunc[1] = &Harl::info;
	levFunc[2] = &Harl::warning;
	levFunc[3] = &Harl::error;

    for (int i = 0; i < 4; ++i)
	{
        if (levels[i] == level)
		{
            (this->*levFunc[i])();
            return;
        }
    }
    std::cout << "Level not found" << std::endl;
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
