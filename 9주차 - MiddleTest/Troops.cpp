#include "Troops.h"
#include "Unit.h"

#include <iostream>

Troops::Troops()
{
	root = new Unit("Troops", true, {});

}

Troops::~Troops()
{
}

void Troops::addUnit(Unit* unit)
{
	
}

void Troops::groupInfoCatapult()
{
}

void Troops::groupInfoInfantry()
{
}

void Troops::groupInfoArchery()
{
}

void Troops::groupInfoSpearman()
{
}

void Troops::groupInfoTank()
{
}

void Troops::groupInfoHorseback()
{
}
