#include "FragTrap.hpp"

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap A;
    DiamondTrap B("Diamond");
    A = B;

    A.attack("Luda");
    A.whoAmI();

    return 0;
}


/*

ClapTrap default constructor called!
FragTrap name constructor called!
ScavTrap name constructor called!
DiamondTrap name constructor called!
ScavTrap Nauman_clap_name attacks Hanan causing 30 points of damage!
My name is Nauman my ClapTrap name is Nauman_clap_name.
DiamondTrap destructor is called!
ScavTrap destructor called!
FragTrap destructor called!
ClapTrap destructor called!

*/