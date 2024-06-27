#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap&    operator=(const DiamondTrap& other);
        ~DiamondTrap();
        DiamondTrap(std::string DiamondTrap);
        void attack(const std::string& target);
        void whoAmI();

    private:
        std::string name;
};



#endif