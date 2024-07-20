#include "Identify.hpp"


int main()
{
	Base *base;
	base = generate();
	identify(base);
	if(base)
	{
		identify(*base);
		delete base;
	}
}
