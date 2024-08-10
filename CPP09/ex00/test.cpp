#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap = {
        {1, "one"},
        {3, "three"},
        {5, "five"},
        {7, "seven"}
    };

    // Using lower_bound
	int key = 1;
    auto it = myMap.lower_bound(key);
    
    if (it != myMap.end()) {
        std::cout << "Lower bound of " << key <<  " is: " << it->first << " -> " << it->second << std::endl;
    } else {
        std::cout << "No lower bound found" << std::endl;
    }

    // Using lower_bound with existing key
    it = myMap.lower_bound(3);
    if (it != myMap.end()) {
        std::cout << "Lower bound of 3 is: " << it->first << " -> " << it->second << std::endl;
    }

    return 0;
}