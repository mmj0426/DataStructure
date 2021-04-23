#include "SkillTree.h"
#include "Skill.h"

#include <iostream>

SkillTree::SkillTree()
{
	std::vector<Skill*> parent_crow;
	addSkill(new Skill("±î¸¶±Í",1, parent_crow));

	std::vector<Skill*> parent_flower;
	addSkill(new Skill("Á×À½ÀÇ ²É", 2, parent_flower));

	std::vector<Skill*> parent_tree;
	addSkill(new Skill("Á×À½ÀÇ ³ª¹«", 3, parent_tree));

	std::vector<Skill*> parent_whiteWolf;
	addSkill(new Skill("Èò ´Á´ë", 4, parent_whiteWolf));

	std::vector<Skill*> parent_bug;
	addSkill(new Skill("Á×À½ÀÇ ¹ú·¹", 6, parent_bug));

	std::vector<Skill*> parent_heart;
	addSkill(new Skill("»ïÄÑÁø ½ÉÀå", 6, parent_heart));

	std::vector<Skill*> parent_blackWolf;
	addSkill(new Skill("°ËÀº ´Á´ë", 7, parent_blackWolf));

	std::vector<Skill*> parent_sun;
	addSkill(new Skill("Á×À½ÀÇ ÅÂ¾ç", 8, parent_sun));

	std::vector<Skill*> parent_root;
	addSkill(new Skill("Á×À½ÀÇ »Ñ¸®", 9, parent_root));

	std::vector<Skill*> parent_bear;
	addSkill(new Skill("°õ", 10, parent_bear));

}

SkillTree::~SkillTree()
{

}

void SkillTree::addSkill(Skill* newSkill)
{
	
}

