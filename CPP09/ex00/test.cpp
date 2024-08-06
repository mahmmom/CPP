#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::stringstream ss;

    // Writing to the stringstream
    ss << "Hello, ";
    ss << "world! ";
    ss << 42;

    // Converting the stream's content to a string
    std::string result = ss.str();

    // Printing the result
    std::cout << result << std::endl;

    // Reading from the stringstream
    std::stringstream ss2(result);
    std::string word;
    int number;

    ss2 >> word;   // Hello,
    ss2 >> word;   // world!
    ss2 >> number; // 42

    std::cout << "Word: " << word << ", Number: " << number << std::endl;

    return 0;
}
