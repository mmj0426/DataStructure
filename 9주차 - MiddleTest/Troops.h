#pragma once
#include <string>

class Unit;
class Item;

class Troops
{
public:
	Troops();
	~Troops();

	void addUnit(Unit* unit);
	void addUnitItem(Item* item);

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
	void SetCurrentDirectory(Unit* _currentDirectory) { current = _currentDirectory; }
	Unit* GetCurrentDirectory() { return current; }

	Unit* find(const std::string& path);
	Unit* find_impl(Unit* directory, const std::string& path);

	bool add(const std::string& path, bool isDir);
	bool add_impl(Unit* directory, const std::string& path, bool isDir);

	void changeTroop(std::string _affiliatedTroop);
	

private:
	Unit* root;
	Unit* current;
};

