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
		// 기존 데이터의 중앙값보다 작으면 최대힙 저장
		if (data <= get())
		{
			maxHeap->push(data);
		}
		// 기존 데이터의 중앙값보다 크면 최소힙 저장
		else
		{
			minHeap->push(data);
		}
		return;
	}


	if (maxHeap->size() < minHeap->size())
	{
		// 기존 데이터의 중앙값보다 크니까 최소힙 저장
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

	// 기존 데이터의 중앙값보다 작으니까 최대힙 저장
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
	// 크기가 같으면 평균
	if (maxHeap->size() == minHeap->size())
	{
		// 중앙값 계산 : 최소힙, 최대힙의 top의 값은 중앙값을 계산할 요소
		return (maxHeap->top() + minHeap->top()) / 2.0;
	}

	if (maxHeap->size() < minHeap->size())
	{
		return minHeap->top();
	}
	return maxHeap->top();
}