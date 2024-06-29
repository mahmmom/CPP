#include "FragTrap.hpp"

int main()
{
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	FragTrap A("Mohamed");
	FragTrap B;
	B = A;
	std::cout << "\033[34mTesting\033[0m" << std::endl;
	B.attack("Luda");
	B.takeDamage(5);
	B.beRepaired(2);
	B.highFivesGuys();
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
}
