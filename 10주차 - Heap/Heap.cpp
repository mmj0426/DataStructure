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

			// ���� ����� �θ� 
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

	// ��Ʈ���� ������ �� ��ȯ
	temp = data.front();
	data.front() = data.back();
	data.back()= temp;

	// ������ �� ����
	data.pop_back();

	// ����� ��Ʈ�� �ڽ��� ��

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
