#pragma once
#include <string>
class Unit;

class Troops
{
public:
	Troops();
	~Troops();

	void addUnit(Unit* unit);

	// ����
	void groupInfoCatapult();
	// ����
	void groupInfoInfantry();
	// �ú�
	void groupInfoArchery();
	// â��
	void groupInfoSpearman();
	// ����
	void groupInfoTank();
	// �⸶
	void groupInfoHorseback();

public :
	
private:
	Unit* root;

};

