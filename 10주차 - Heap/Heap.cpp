#include "Heap.h"

Heap::Heap(bool _isMaxheap)
{
	isMaxheap = _isMaxheap;
}

Heap::~Heap()
{
}

void Heap::push(int _data)
{
	data.push_back(_data);

	int index = data.size() - 1;

	if (isMaxheap)
	{
		while (index != 0 && data[(index - 1) / 2] < _data)
		{
			int temp = data[index];
			data[index] = data[(index - 1) / 2];
			data[(index - 1) / 2] = temp;

			// 현재 노드의 부모 
			index = (index - 1) / 2;
		}
	}
	else
	{
		while (index != 0 && data[(index - 1) / 2] > _data)
		{
			int temp = data[index];
			data[index] = data[(index - 1) / 2];
			data[(index - 1) / 2] = temp;

			index = (index - 1) / 2;
		}
	}
}

void Heap::pop()
{
	int temp = 0;

	// 루트노드와 마지막 값 교환
	temp = data.front();
	data.front() = data.back();
	data.back()= temp;

	// 마지막 값 삭제
	data.pop_back();

	// 변경된 루트와 자식의 비교

	int parentIndex = 0;
	
	if (isMaxheap)
	{
		while (parentIndex > (data.size() - 1))
		{

			if (data[parentIndex] < data[parentIndex * 2 + 1])
			{
				int temp = data[parentIndex];
				data[parentIndex] = data[parentIndex * 2 + 1];
				data[parentIndex * 2 + 1] = temp;

				parentIndex = parentIndex * 2 + 1;
			}
			else if (data[parentIndex] > data[parentIndex * 2 + 2])
			{
				int temp = data[parentIndex];
				data[parentIndex] = data[parentIndex * 2 + 2];
				data[parentIndex * 2 + 2] = temp;

				parentIndex = parentIndex * 2 + 2;
			}


		}
	}
}

int Heap::top()
{
	return data.front();
}

int Heap::size()
{
	return data.size();
}
