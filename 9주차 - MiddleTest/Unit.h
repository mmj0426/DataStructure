#pragma once

#include <string>
#include <vector>

enum class ETroop
{
	Catapult,
	Infantry,
	Archery,
	Spearman,
	Tank,
	Horseback
};

class Unit
{
public : 
	Unit(){}
	Unit(std::string _name, bool _isTroop,	std::vector<Unit*>_children)
	{
		name = _name;
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

	ETroop GetAffiliatedTroop(){return affiliated_troop;}

public :

	// ������ �ҼӺδ�
	ETroop affiliated_troop;
	
	std::string name;
	bool isTroop;
	std::vector<Unit*>children;
};

class Catapult : public Unit
{
public:
	Catapult()
	{
		affiliated_troop = ETroop::Catapult;
		name = "������";
		isTroop = false;
	}
	~Catapult() {}

};

class Infantry : public Unit
{
public:
	Infantry()
	{
		affiliated_troop = ETroop::Infantry;
		name = "����";
		isTroop = false;
	}
	~Infantry() {}

};

class Archery : public Unit
{
public:
	Archery()
	{
		affiliated_troop = ETroop::Archery;
		name = "�ú�";
		isTroop = false;
	}
	~Archery() {}

};

class Spearman : public Unit
{
public:
	Spearman()
	{
		affiliated_troop = ETroop::Spearman;
		name = "â��";
		isTroop = false;
	}
	~Spearman() {}

};

class Tank : public Unit
{
public:
	Tank()
	{
		affiliated_troop = ETroop::Tank;
		name = "������";
		isTroop = false;
	}
	~Tank() {}

};


class Horseback : public Unit
{
public:
	Horseback()
	{
		affiliated_troop = ETroop::Horseback;
		name = "�⸶��";
		isTroop = false;
	}
	~Horseback() {}

};

