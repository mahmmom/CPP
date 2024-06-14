#include "replace.hpp"

int main(int argc, char **av)
{
    if (argc != 4)
	{
        std::cout << "Invalid arguments. Use: ./replace <filename> <string1> <string2>" << std::endl;
        return (1);
    }

    Replace replace1(av[1],"Outfile.replace",av[2],av[3]);

	replace1.setupFile();

    return (0);
}
