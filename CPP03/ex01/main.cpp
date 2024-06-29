#include "ScavTrap.hpp"

int main()
{
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	ScavTrap A("Mohamed");
	ScavTrap B;
	B = A;
	std::cout << "\033[34mTesting\033[0m" << std::endl;
	B.attack("Luda");
	B.takeDamage(5);
	B.beRepaired(2);
	B.guardGate();
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
}
