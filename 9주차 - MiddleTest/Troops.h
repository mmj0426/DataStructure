#pragma once
#include <string>
class Unit;

class Troops
{
public:
	Troops();
	~Troops();

	void addUnit(Unit* unit);

	// 투석
	void groupInfoCatapult();
	// 보병
	void groupInfoInfantry();
	// 궁병
	void groupInfoArchery();
	// 창병
	void groupInfoSpearman();
	// 전차
	void groupInfoTank();
	// 기마
	void groupInfoHorseback();

public :
	
private:
	Unit* root;

};

