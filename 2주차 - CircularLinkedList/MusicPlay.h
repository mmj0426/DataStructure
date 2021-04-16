#pragma once

#include <string>

typedef struct ListNode
{
	std::string data;
	struct ListNode* next;
} ListNode;

class MusicPlay
{
public : 
	int ShowMenu();
	void AddMusic();
	void ShowPlayList(ListNode* head);
	void Play();
	void Exit();

public : 
	bool GetIsRunning() const { return isRunning; }
	int GetCmd() const {return cmd;}
	ListNode* GetHead() const {return head;}

private : 
	int cmd;
	std::string music_name;
	bool isRunning = true;

private : 
	ListNode* head = nullptr;
	void InsertAtEnd(ListNode** head, std::string data);
};

