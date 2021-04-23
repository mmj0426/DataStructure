#pragma once

#include <string>
#include <vector>

class Skill
{
public : 
	std::string name;
	int currentPoint;
	int maxPoint;
	std::vector<Skill*> parents;
	std::vector<Skill*> children;

	Skill(std::string _name, int _maxpoint, std::vector<Skill*> _parents)
	{
		name = _name;
		currentPoint = 0;
		maxPoint = _maxpoint;
		parents = _parents;
		children = {};
	}
	~Skill()
	{
		for (auto parent : parents)
		{
			delete parent;
		}

		for (auto child : children)
		{
			delete child;
		}
	}
};