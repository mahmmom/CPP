#include "FragTrap.hpp"

int main()
{
	FragTrap A("Mohamed");
	FragTrap B;
	B = A;

	B.attack("Luda");
	B.takeDamage(5);
	B.beRepaired(2);
	B.highFivesGuys();
}
