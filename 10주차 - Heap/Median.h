#pragma once
class Heap;

class Median
{
public : 
	Median();
	~Median();

	void insert(int data);
	double get();

private : 
	Heap* maxHeap;
	Heap* minHeap;
};

