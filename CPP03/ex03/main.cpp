#include "DiamondTrap.hpp"

int main()
{
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
    DiamondTrap A;
    DiamondTrap B("Diamond");
    A = B;
	std::cout << "\033[34mTesting\033[0m" << std::endl;
    A.attack("Luda");
    A.whoAmI();
	A.takeDamage(5);
	A.beRepaired(10);
	A.guardGate();
	A.highFivesGuys();
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
}
