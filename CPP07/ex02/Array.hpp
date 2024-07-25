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
    	Array() : _arr(NULL), _size(0)
		{

		};

    	Array(unsigned int n) : _size(n)
		{
			_arr = new T[n];
		}

   		Array(const Array& other) : _arr(NULL), _size(0)
		{
			*this = other;
		};

		Array& operator=(const Array& other)
		{
			if(this != &other)
			{
				this->_size = other._size;
				if(this->_arr)
					delete [] _arr;
				this->_arr = new T[this->_size];
				for (size_t i = 0; i < this->_size; i++)
					_arr[i] = other._arr[i];
			}
			return *this;
		}

    	~Array()
		{	
			if(_arr)
				delete [] _arr;
		};
		
		T& operator[]( size_t index)
		{
			if(index >= this->_size)
				throw outOfBoundary();
			return _arr[index];
		};

		const T& operator[]( size_t index) const
		{
			if(index >= this->_size)
				throw outOfBoundary();
			return _arr[index];
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


#include "Array.tpp"

#endif