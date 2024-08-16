#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

template <typename T, size_t N, typename F>
void iter(T (&array)[N], size_t length, F function)
{
	if (N < length)
		return std::cerr << "Invalid index" << std::endl, void();
    for (size_t i = 0; i < length; ++i)
        function(array[i]);
}

#endif

/*
Reference to Array:

-- By using a reference, (&array), you avoid copying the array. Instead, you directly refer to the original array.
-- This is efficient because no additional memory is used for copying, and changes to the array inside the function reflect in the original array (if applicable).

Compile-Time Size:

-- When the function is called with an array, the compiler automatically captures the size of the array N at compile time.
-- This means N is a constant known to the compiler, which allows the compiler to perform checks and optimizations based on the array's size.

Benefits of Compile-Time Size Capture:

-- Safety: The function knows the exact size of the array, which allows it to check if the provided length is valid. This prevents out-of-bounds access.
-- No Extra Parameters: There's no need for the caller to provide the array size explicitly, reducing the risk of mismatched sizes.
-- Optimizations: The compiler can generate more efficient code because it knows the array size.

*/