#pragma once

class Node;

class Traversal
{
public : 
	void preOrder(Node* start);
	void inOrder(Node* start);
	void postOrder(Node* start);
	void levelOrder(Node* start);
};

