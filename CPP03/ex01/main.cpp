#include "ScavTrap.hpp"

int main()
{
	ScavTrap A("Mohamed");
	ScavTrap B;
	B = A;

	B.attack("Luda");
	B.takeDamage(5);
	B.beRepaired(2);
	B.guardGate();
}
