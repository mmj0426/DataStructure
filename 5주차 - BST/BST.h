#pragma once

class Node;

class BST
{
public : 
	BST();
	~BST(){}

	Node* root;

	Node* find(int value);

	void insert(int value);

	void inorder();

	void descending();

	void deleteValue(int value);

private : 
	Node* find_impl(Node* current, int value);

	void insert_impl(Node* current, int value);

	void inorder_impl(Node* start);

	void decending_impl(Node* start);

	Node* delete_impl(Node*start, int value);
	
public : 
	Node* successor(Node* start);
};

