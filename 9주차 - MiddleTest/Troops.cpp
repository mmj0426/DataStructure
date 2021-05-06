#include "Troops.h"
#include "Unit.h"

#include <iostream>

Troops::Troops()
{
	root = new Unit("/", true, {});
	current = root;

	add("����", true);
	add("����", true);
	add("�ú�", true);
	add("â��", true);
	add("����", true);
	add("�⸶", true);
}

Troops::~Troops()
{

}

void Troops::addUnit(Unit* unit)
{
	std::string affiliated_Troop;

	switch (unit->GetAffiliatedTroop())
	{
	case ETroop::Catapult:
		affiliated_Troop = "����";
		break;

	case ETroop::Infantry:
		affiliated_Troop = "����";
		break;

	case ETroop::Archery:
		affiliated_Troop = "�ú�";
		break;

	case ETroop::Spearman:
		affiliated_Troop = "â��";
		break;

	case ETroop::Tank:
		affiliated_Troop = "����";
		break;

	case ETroop::Horseback:
		affiliated_Troop = "�⸶";
		break;

	default:
		break;
	}


	if (current->name == affiliated_Troop)
	{
		add(unit->name, false);
		return;
	}
	else
	{
		changeTroop(affiliated_Troop);
		add(unit->name, false);
		return;
	}

}

void Troops::addUnitItem(Item* item)
{
	
}

void Troops::groupInfoCatapult()
{
	auto path =  "/����";

	auto found = find(path);

	if (!found)
	{
		std::cout << path << " ��ΰ� �������� �ʽ��ϴ�." << std::endl;
		return;
	}

	std::cout << std::endl << "�׷� : " << found->children.size() / 3 + 1 << " ������ : " << found->children.size() << std::endl;;
}

void Troops::groupInfoInfantry()
{
	auto path = "/����";

	auto found = find(path);

	if (!found)
	{
		std::cout << path << " ��ΰ� �������� �ʽ��ϴ�." << std::endl;
		return;
	}

	std::cout << std::endl << "�׷� : " << found->children.size() /3 + 1<< " ���� : " << found->children.size() << std::endl;;
}

void Troops::groupInfoArchery()
{
	auto path = "/�ú�";

	auto found = find(path);

	if (!found)
	{
		std::cout << path << " ��ΰ� �������� �ʽ��ϴ�." << std::endl;
		return;
	}


	std::cout << std::endl << "�׷� : " << found->children.size() / 3 + 1 << " �ú� : " << found->children.size() << std::endl;;
}

void Troops::groupInfoSpearman()
{
	auto path = "/â��";

	auto found = find(path);

	if (!found)
	{
		std::cout << path << " ��ΰ� �������� �ʽ��ϴ�." << std::endl;
		return;
	}

	std::cout << std::endl << "�׷� : " << found->children.size() / 3 + 1 << " â�� : " << found->children.size() << std::endl;;
}

void Troops::groupInfoTank()
{
	auto path = "/����";

	auto found = find(path);

	if (!found)
	{
		std::cout << path << " ��ΰ� �������� �ʽ��ϴ�." << std::endl;
		return;
	}

	std::cout << std::endl << "�׷� : " << found->children.size() / 3 + 1 << " ������ : " << found->children.size() << std::endl;;
}

void Troops::groupInfoHorseback()
{
	auto path = "/�⸶";

	auto found = find(path);

	if (!found)
	{
		std::cout << path << " ��ΰ� �������� �ʽ��ϴ�." << std::endl;
		return;
	}

	std::cout << std::endl << "�׷� : " << found->children.size() / 3 + 1 << " �⸶�� : " << found->children.size() << std::endl;;
}

Unit* Troops::find(const std::string& path)
{
	if (path[0] == '/')
	{
		return find_impl(root, path.substr(1));
	}
	else
	{
		return find_impl(current, path);
	}
}

bool Troops::add(const std::string& path, bool isDir)
{
	if (path[0] == '/')
	{
		return add_impl(root, path.substr(1), isDir);
	}
	else
	{
		return add_impl(current, path, isDir);
	}
}


Unit* Troops::find_impl(Unit* troop, const std::string& path)
{
	if (path.empty())
	{
		return troop;
	}
	auto separate = path.find('/');

	std::string current_path = separate == std::string::npos ? path : path.substr(0, separate);

	std::string rest_path = separate == std::string::npos ? "" : path.substr(separate + 1);

	auto found = std::find_if(troop->children.begin(), troop->children.end(),
		[&](const Unit* child)
		{
			return child->name == current_path;
		});

	if (found != troop->children.end())
	{
		return find_impl(*found, rest_path);
	}
	return nullptr;
}

bool Troops::add_impl(Unit* unit, const std::string& path, bool isDir)
{
	if (!unit->isTroop)
	{
		std::cout << unit->name << "��(��) �����Դϴ�." << std::endl;
		return false;
	}

	auto separate = path.find('/');

	if (separate == std::string::npos)
	{
		auto found = std::find_if(unit->children.begin(), unit->children.end(),
			[&](const Unit* child)
			{
				return child->name == path;
			});

		unit->children.push_back(new Unit{ path,isDir,{} });
		return true;
	}

	std::string next_dir = path.substr(0, separate);

	auto found = std::find_if(unit->children.begin(), unit->children.end(),
		[&](const Unit* child)
		{
			return child->name == next_dir && child->isTroop;
		});

	if (found != unit->children.end())
	{
		return add_impl(*found, path.substr(separate + 1), isDir);
	}

	std::cout << unit->name << "�� " << next_dir << " �̸��� �δ밡 �����ϴ�." << std::endl;

	return false;
}

void Troops::changeTroop(std::string _affiliatedTroop)
{
	current = root;

	auto found = find(_affiliatedTroop);

	if (found && found->isTroop)
	{
		current = found;
		return;
	}

	std::cout << _affiliatedTroop << "��θ� ã�� �� �����ϴ�." << std::endl;
	return;

}
