#include "MusicPlay.h"

#include <iostream>

int MusicPlay::ShowMenu()
{
	std::cout<<"1. 음악 추가" <<std::endl;
	std::cout << "2. 목록 출력" << std::endl;
	std::cout << "3. 재생 시작" << std::endl;
	std::cout << "4. 종료" << std::endl;
	std::cout << "명령 입력 >> ";

	std::cin>>cmd;

	return cmd;
}

// Index == 1
void MusicPlay::AddMusic()
{
	std::cout << std::endl << "추가할 음악 이름 : ";
	std::cin>>music_name;

	InsertAtEnd(&head, music_name);
}

// Index == 2
void MusicPlay::ShowPlayList(ListNode* head)
{
	if (nullptr == head)
	{
		std::cout<<std::endl << "추가된 곡이 없습니다." << std::endl;
		return;
	}

	ListNode* current = head;
	int index = 0;

	std::cout << std::endl << "<재생 목록>" <<std::endl;

	do 
	{
		index++;

		std::cout << index << ". "<< current->data << std::endl ;

		current = current->next;

	} while (current != head);

	std::cout << std::endl;
}


//Index == 3
void MusicPlay::Play()
{
	if (nullptr == head)
	{
		std::cout<<std::endl << "추가된 곡이 없습니다." << std::endl;
		return;
	}

	ListNode* current = head;
	int cmd;
	
	std::cout << current->data << " 재생 중..." << std::endl;
	std::cout << "다음 곡 재생(1), 종료 (0) >";
	std::cin >> cmd;
	std::cout << std::endl;

	while (true)
	{
		switch (cmd)
		{
		case 1:
			current = current->next;
			std::cout << current->data << " 재생 중..." << std::endl;
			std::cout << "다음 곡 재생(1), 종료 (0) >";
			std::cin >> cmd;
			std::cout << std::endl;
			break;

		case 0:
			return;
			break;

		default:
			break;
		}
	}
}

//Index == 4
void MusicPlay::Exit()
{
	isRunning = false;
	return;
}

// List 맨 끝에 목록 추가
void MusicPlay::InsertAtEnd(ListNode* *head, std::string data)
{
	ListNode* inserted = new ListNode;

	inserted->data = data;

	if (nullptr == *head)
	{
		*head = inserted;
		inserted->next = *head;
	}
	else
	{
		ListNode* tail = *head;
		while (tail->next != *head)
		{
			tail = tail->next;
		}
		tail->next = inserted;
		inserted->next = *head;
	}
}

