#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		virtual ~ScavTrap();
		ScavTrap(std::string scav);
		void	attack(const std::string& target);
		void	guardGate();
	private:
};


#endif