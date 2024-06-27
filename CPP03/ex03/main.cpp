#include "FragTrap.hpp"

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dt("Diamond");

    dt.attack("Enemy");
    dt.whoAmI();

    return 0;
}
