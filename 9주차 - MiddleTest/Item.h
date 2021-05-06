#pragma once

#include <string>
#include "Unit.h"

class Item
{

protected:
	std::string name;
	std::string troopName;
	Item* necessary;
};

class CatapultFlag : public Item
{
public : 
	CatapultFlag()
	{
		name = "���";
		troopName = "����";
	}
	~CatapultFlag(){}
};

class InfantrySword : public Item
{
public:
	InfantrySword()
	{
		name = "��";
		troopName = "����";
	}
	~InfantrySword() {}
};

class ArcheryBow : public Item
{
public:
	ArcheryBow()
	{
		name = "Ȱ";
		troopName = "�ú�";
	}
	~ArcheryBow() {}
};

class Spear : public Item
{
public:
	Spear()
	{
		name = "â";
		troopName = "â��";
	}
	~Spear() {}
};

class Horse : public Item
{
public:
	Horse()
	{
		name = "��";
		troopName = "����";
		// �⸶..
	}
	~Horse() {}
};

class Jockey : public Item
{
public:
	Jockey()
	{
		name = "���";
		troopName = "����";
	}
	~Jockey() {}
};

class Saddle : public Item
{
public:
	Saddle()
	{
		name = "����";
		troopName = "�⸶";
	}
	~Saddle() {}
};
