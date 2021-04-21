#pragma once
#include <string>
#include <vector>

class Node
{
public : 
	std::string name;
	bool isDir;
	std::vector<Node*>children;

public : 
	Node(std::string _name, bool _isDir, std::vector<Node*>_children)
	{
		name = _name;
		isDir = _isDir;
		children = _children;
	}
	~Node()
	{
		for (auto& child : children)
		{
			delete child;
		}
	}
};