#pragma once
#include <map>
#include <iostream>

template<typename T, int capacity>

class deque
{
private:
	// 각 메모리 청크의 주소값을 가지고 있음
	std::map<int, T**> deqmap;

	// map의 Key(first)값들
	int firstKey;
	int lastKey;

	// 고정배열 Index
	int front;
	int rear;

public:

	deque()
	{
		firstKey = INT_MAX / 2;
		lastKey = INT_MAX / 2;

		front = capacity / 2;
		rear = (capacity / 2) + 1;

		deqmap[firstKey] = new T * [capacity]();
	}

	~deque()
	{
		for (size_t index = firstKey; index <= lastKey; index++)
		{
			for (size_t i = 0; i < capacity; i++)
			{
				if (deqmap[index][i] != nullptr)
				{
					delete deqmap[index][i];
				}
			}
			delete deqmap[index];
		}
	}

	void push_front(T _data)
	{
		front--;

		if (front < 0)
		{
			front = capacity / 2;

			firstKey--;
			// Add Chunk
			deqmap[firstKey] = new T * [capacity]();

			deqmap[firstKey][capacity / 2] = new T;
			*deqmap[firstKey][capacity / 2] = _data;
		}
		else
		{
			if (nullptr == deqmap[firstKey][front])
			{
				deqmap[firstKey][front] = new T;
				*deqmap[firstKey][front] = _data;
			}
		}

	}

	void push_back(T _data)
	{
		rear++;

		if (rear >= capacity)
		{
			rear = (capacity / 2) + 1;
			
			lastKey++;
			// Add Chunk
			deqmap[lastKey] = new T * [capacity]();

			deqmap[lastKey][(capacity / 2) + 1] = new T;
			*deqmap[lastKey][(capacity / 2) + 1] = _data;

		}
		else
		{
			if (nullptr == deqmap[lastKey][rear])
			{
				deqmap[lastKey][rear] = new T;
				*deqmap[lastKey][rear] = _data;
				return;
			}
		}
	}

	void printElement()
	{
		for (size_t index = firstKey; index <= lastKey; index++)
		{
			for (size_t i = 0; i < capacity; i++)
			{
				if (deqmap[index][i] != nullptr)
				{
					std::cout << *deqmap[index][i] << "  ";
				}
			}
		}

	}

};
