#include "ClapTrap.hpp"

int main()
{
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	ClapTrap A("Mohamed");
	ClapTrap B;
	B = A;
	std::cout << "\033[34mTesting\033[0m" << std::endl;
	B.attack("Luda");
	B.takeDamage(9);
	B.beRepaired(1);
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
}
