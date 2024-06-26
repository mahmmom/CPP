#include "ClapTrap.hpp"




int main()
{
	ClapTrap A("Mohamed");
	ClapTrap B;
	B = A;

	B.attack("Luda");
	B.takeDamage(5);
	B.beRepaired(2);
}
