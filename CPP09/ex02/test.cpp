#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Function to perform binary search
int binarySearch(const std::vector<int>& arr, int left, int right, int key)
{
    while (left <= right)
	{
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
			return mid;
        if (arr[mid] < key)
			left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

// Function to insert an element into a sorted array
void insert(std::vector<int>& arr, int pos, int val)
{
    arr.insert(arr.begin() + pos, val);
}

// Main merge-insert sort function
void mergeInsertSort(std::vector<int>& arr)
{
    if (arr.size() <= 1) return;

    std::vector<int> sorted;
    std::vector<int> unsorted;

    // Step 1 & 2: Pair up elements and sort each pair
    for (size_t i = 0; i < arr.size() - 1; i += 2)
	{
        if (arr[i] > arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
        sorted.push_back(arr[i + 1]);
        unsorted.push_back(arr[i]);
    }

    // If there's an odd number of elements, add the last one to unsorted
    if (arr.size() % 2 != 0)
	{
        unsorted.push_back(arr.back());
    }

    // Step 3: Recursively sort the larger elements
    mergeInsertSort(sorted);

    // Step 4: Insert the remaining elements using binary insertion sort
    sorted.insert(sorted.begin(), unsorted[0]);

    for (size_t i = 1; i < unsorted.size(); ++i)
	{
        int pos = binarySearch(sorted, 0, i, unsorted[i]);
        insert(sorted, pos, unsorted[i]);
    }

    // Copy the sorted result back to the original array
    arr = sorted;
}

int main()
{
    // Seed for random number generation
    std::srand(std::time(0));

    // Create a vector to hold our test data
    std::vector<int> arr;

    // Generate 20 random positive integers between 1 and 100
    for (int i = 0; i < 20; ++i)
	{
        arr.push_back(std::rand() % 100 + 1);
    }

    // Print the unsorted array
    std::cout << "Unsorted array:" << std::endl;
    for (size_t i = 0; i < arr.size(); ++i)
	{
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Sort the array using merge-insert sort
    mergeInsertSort(arr);

    // Print the sorted array
    std::cout << "Sorted array:" << std::endl;
    for (size_t i = 0; i < arr.size(); ++i)
	{
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}