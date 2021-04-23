#include "SkillTree.h"
#include "Skill.h"

#include <iostream>

SkillTree::SkillTree()
{
	std::vector<Skill*> parent_crow;
	addSkill(new Skill("���",1, parent_crow));

	std::vector<Skill*> parent_flower;
	addSkill(new Skill("������ ��", 2, parent_flower));

	std::vector<Skill*> parent_tree;
	addSkill(new Skill("������ ����", 3, parent_tree));

	std::vector<Skill*> parent_whiteWolf;
	addSkill(new Skill("�� ����", 4, parent_whiteWolf));

	std::vector<Skill*> parent_bug;
	addSkill(new Skill("������ ����", 6, parent_bug));

	std::vector<Skill*> parent_heart;
	addSkill(new Skill("������ ����", 6, parent_heart));

	std::vector<Skill*> parent_blackWolf;
	addSkill(new Skill("���� ����", 7, parent_blackWolf));

	std::vector<Skill*> parent_sun;
	addSkill(new Skill("������ �¾�", 8, parent_sun));

	std::vector<Skill*> parent_root;
	addSkill(new Skill("������ �Ѹ�", 9, parent_root));

	std::vector<Skill*> parent_bear;
	addSkill(new Skill("��", 10, parent_bear));

}

SkillTree::~SkillTree()
{

}

void SkillTree::addSkill(Skill* newSkill)
{
	
}

