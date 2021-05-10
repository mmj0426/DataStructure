#include "Median.h"
#include "Heap.h"

Median::Median()
{
	maxHeap = new Heap(true);
	minHeap = new Heap(false);
}

Median::~Median()
{
	delete maxHeap;
	delete minHeap;
}

void Median::insert(int data)
{
	if (maxHeap->size() == 0)
	{
		maxHeap->push(data);
		return;
	}

	if (maxHeap->size() == minHeap->size())
	{
		// ���� �������� �߾Ӱ����� ������ �ִ��� ����
		if (data <= get())
		{
			maxHeap->push(data);
		}
		// ���� �������� �߾Ӱ����� ũ�� �ּ��� ����
		else
		{
			minHeap->push(data);
		}
		return;
	}


	if (maxHeap->size() < minHeap->size())
	{
		// ���� �������� �߾Ӱ����� ũ�ϱ� �ּ��� ����
		if (data > get())
		{
			maxHeap->push(minHeap->top());
			minHeap->pop();
			minHeap->push(data);
		}
		else
		{
			maxHeap->push(data);
		}
		return;

	}

	// ���� �������� �߾Ӱ����� �����ϱ� �ִ��� ����
	if (data < get())
	{
		minHeap->push(maxHeap->top());
		maxHeap->pop();
		maxHeap->push(data);
	}
	else
	{
		minHeap->push(data);
	}
}

double Median::get()
{
	// ũ�Ⱑ ������ ���
	if (maxHeap->size() == minHeap->size())
	{
		// �߾Ӱ� ��� : �ּ���, �ִ����� top�� ���� �߾Ӱ��� ����� ���
		return (maxHeap->top() + minHeap->top()) / 2.0;
	}

	if (maxHeap->size() < minHeap->size())
	{
		return minHeap->top();
	}
	return maxHeap->top();
}