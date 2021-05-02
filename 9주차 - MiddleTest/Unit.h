#pragma once

#include <string>
#include <vector>

class Unit
{
public : 
	Unit(){}
	Unit(std::string _troopName, bool _isTroop,	std::vector<Unit*>_children)
	{
		troopName = _troopName;
		isTroop = _isTroop;
		children = _children;
	}

	~Unit()
	{
		for (auto& child : children)
		{
			delete child;
		}
	}

public : 
	std::string troopName;
	bool isTroop;
	std::vector<Unit*>children;
};

