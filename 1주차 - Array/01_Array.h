#pragma once
#include <iostream>

template<typename T, int size>

class Array
{
private : 
	T* array;

public : 
	Array()
	{
		array = new T[size];
	}

	T& operator[] (T index)
	{
		if (index < 0 || index >= size)
		{
			std::cout << "Array index out of bound exception" << std::endl;
			exit(-1);
		}

		return array[index];
	}

	int GetSize() const { return size; }

	T GetBegin() const { return array[0]; }

	T GetEnd() const { return array[size-1]; }

	~Array() { delete [] array; }

};

