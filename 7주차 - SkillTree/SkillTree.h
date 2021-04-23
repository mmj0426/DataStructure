#pragma once

class Skill;

class SkillTree
{
public : 
	SkillTree();
	~SkillTree();

	void addSkill(Skill* newSkill);


private : 
	Skill* root;
	Skill* currentSkill;

};

