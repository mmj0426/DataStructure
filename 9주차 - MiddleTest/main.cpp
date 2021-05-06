#include "Troops.h"
#include "Unit.h"
#include "Item.h"

int main()
{
	// �δ뿡 ���� �߰� �����ڵ�
	// addUnit�Լ��� ���ؼ��� ���� �߰� ����
	Troops* troops = new Troops();

	// ������ 4, ������ 1
	troops->addUnit(new Catapult());
	troops->addUnit(new Catapult());
	troops->addUnit(new Catapult());
	troops->addUnit(new Catapult());

	troops->addUnit(new Infantry());
	troops->addUnit(new Archery());
	troops->addUnit(new Spearman());
	troops->addUnit(new Tank());
	troops->addUnit(new Horseback());
	
	// �δ� ���� ���
	troops->groupInfoCatapult();
	troops->groupInfoInfantry();
	troops->groupInfoArchery();
	troops->groupInfoSpearman();
	troops->groupInfoTank();
	troops->groupInfoHorseback();

	troops->addUnitItem(new CatapultFlag());

	Horse* tank = new Horse();
	troops->addUnitItem(tank);
	troops->addUnitItem(new Jockey());

	troops->addUnitItem(new Horse());

	troops->addUnit(new Catapult());
	troops->groupInfoCatapult();
}