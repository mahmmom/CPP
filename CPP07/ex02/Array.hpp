#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array
{
private:
    T* _arr;
    size_t _size;

public:
    Array(): _arr(NULL), _size(0){};

    Array(unsigned int n): _size(n)
	{
		_arr = new T[n]();
	};

    Array(const Array& other): _arr(NULL), _size(0)
	{
		*this = other;
	};

    Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			_size = other._size;
			if (_arr)
				delete[] _arr;
			_arr = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_arr[i] = other._arr[i];
		}
		return *this;
	};

    ~Array()
	{
		if (_arr)
			delete[] _arr;
	};

    T& operator[](size_t index)
	{
		if (index >= _size)
			throw outOfBoundary();
		return _arr[index];
	};

    const T& operator[](size_t index) const
	{
		if (index >= _size)
			throw outOfBoundary();
		return _arr[index];
	};

    size_t size() const
	{
		return _size;
	};

    class outOfBoundary : public std::exception
    {
		public:
		const char* what() const throw()
		{
			return "Index out of boundary";
		};
    };
};

#endif