#include "ScalarConverter.hpp"


int main(int ac, char** av)
{
	if(ac!= 2)
		std::cerr << "Invalid Arguemnt, Enter ./convert <string>" << std::endl;
	try
	{
		ScalarConverter::convert(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}




// int main() {
//     const char* str = "10.0f";
//     char* end;
    
//     // Convert string to double
//     double value = strtod(str, &end);
    
//     // Check for various errors
//     if (errno == ERANGE)
// 	{
//         std::cerr << "Range error occurred: " << std::endl;
//     }
    
//     // Check if the conversion was successful
// 	if (end == str)
// 	{
//         std::cerr << "No digits were found" << std::endl;
//     }
// 	else
// 	{
//         std::cout << "Converted value: " << value << std::endl;
//         std::cout << "Remaining string: " << end << std::endl;
//     }
    
//     return 0;
// }