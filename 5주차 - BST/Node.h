#pragma once

class Node
{
public : 

	Node(int value, Node* _left, Node* _right)
	{
		data = value;
		left = _left;
		right = _right;
	}

	~Node(){}

	int data;
	Node* left;
	Node* right;
};