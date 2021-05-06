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
		name = "깃발";
		troopName = "투석";
	}
	~CatapultFlag(){}
};

class InfantrySword : public Item
{
public:
	InfantrySword()
	{
		name = "검";
		troopName = "보병";
	}
	~InfantrySword() {}
};

class ArcheryBow : public Item
{
public:
	ArcheryBow()
	{
		name = "활";
		troopName = "궁병";
	}
	~ArcheryBow() {}
};

class Spear : public Item
{
public:
	Spear()
	{
		name = "창";
		troopName = "창병";
	}
	~Spear() {}
};

class Horse : public Item
{
public:
	Horse()
	{
		name = "말";
		troopName = "전차";
		// 기마..
	}
	~Horse() {}
};

class Jockey : public Item
{
public:
	Jockey()
	{
		name = "기수";
		troopName = "전차";
	}
	~Jockey() {}
};

class Saddle : public Item
{
public:
	Saddle()
	{
		name = "안장";
		troopName = "기마";
	}
	~Saddle() {}
};
