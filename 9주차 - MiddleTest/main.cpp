#include "Troops.h"
#include "Unit.h"
#include "Item.h"

int main()
{
	// 부대에 유닛 추가 예시코드
	// addUnit함수를 통해서만 유닛 추가 가능
	Troops* troops = new Troops();

	// 투석병 4, 나머지 1
	troops->addUnit(new Catapult());
	troops->addUnit(new Catapult());
	troops->addUnit(new Catapult());
	troops->addUnit(new Catapult());

	troops->addUnit(new Infantry());
	troops->addUnit(new Archery());
	troops->addUnit(new Spearman());
	troops->addUnit(new Tank());
	troops->addUnit(new Horseback());
	
	// 부대 정보 출력
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