#pragma once
#include <string>

class Node
{
public:
	Node(std::string pos, Node* _first, Node* _second)
	{
		position = pos;
		first = _first;
		second = _second;
	}
	~Node(){}


public:
	std::string position;

	Node* first;
	Node* second;

};

