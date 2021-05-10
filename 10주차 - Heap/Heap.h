#pragma once
#include <vector>

class Heap
{
public : 
	Heap(){}
	Heap(bool _isMaxheap);
	~Heap();

public : 
	void push(int _data);
	void pop();
	int top();
	int size();


private : 
	std::vector<int> data;
	bool isMaxheap;
};

