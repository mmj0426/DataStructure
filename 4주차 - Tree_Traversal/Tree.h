#pragma once
#include <string>

class Node;

class Tree
{
public : 
	Tree(const std::string& pos);
	~Tree();

	bool addChildNode(const std::string& manager, const std::string& child);
	Node* find(Node* root, const std::string& value);

public : 
	Node* GetRoot()const {return root;}

private : 
	Node* root;

};

