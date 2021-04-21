#include "Commands.h"
#include "File_System.h"

#include <iostream>


void ShowFileCommand::Run()
{
	auto path = File_System::GetInstance()->GetCurrentDirectory()->name;
	if (path != "/")
	{
		path = "/" + path;
	}

	auto found = File_System::GetInstance()->find(path);

	if (!found)
	{
		std::cout << path << " ��ΰ� �������� �ʽ��ϴ�." << std::endl;
		return;
	}

	if (found->isDir)
	{
		for (auto child : found->children)
		{
			std::cout << (child->isDir ? "d " : "- ") << child->name << std::endl;
		}
	}
	else
	{
		std::cout <<"- " << found->name << std::endl;
	}

	std::cout << std::endl;
}

void ChangeDirectoryCommand::Run()
{
	std::string changeDirectoryName;

	std::cout << "���� ���丮 �̸� > ";
	std::cin >> changeDirectoryName;

	auto found = File_System::GetInstance()->find(changeDirectoryName);
	if (found && found->isDir)
	{
		File_System::GetInstance()->SetCurrentDirectory(found);
		std::cout << "���� ���丮�� "<< File_System::GetInstance()->GetCurrentDirectory()->name << "�� �̵��մϴ�." << std::endl << std::endl;
		return;
	}

	std::cout << changeDirectoryName << "��θ� ã�� �� �����ϴ�." << std::endl;
	return;

	std::cout<<std::endl;
}

void MakeDirectoryCommand::Run()
{
	std::string newDirectoryName;

	std::cout << "���� ���丮 �̸� > ";
	std::cin >> newDirectoryName;

	File_System::GetInstance()->add(newDirectoryName,true);
	std::cout << std::endl;
}

void MakeFileCommand::Run()
{
	std::string newFileName;

	std::cout << "���� ���� �̸� > ";
	std::cin >> newFileName;

	File_System::GetInstance()->add(newFileName,false);
	std::cout << std::endl;
}

void ShowCommandList::Run() 
{
	std::cout << "<��ɾ� ���>" << std::endl;
	std::cout << "1. ls : ���� ���丮�� ���Ե� ���丮, ���� ���" << std::endl;
	std::cout << "2. cd : ���� ���丮 ����" << std::endl;
	std::cout << "3. mkdir : ���丮 ����" << std::endl;
	std::cout << "4. pwd : ���� ��� ���" << std::endl;
	std::cout << "5. vi : ���� ����" << std::endl;
	std::cout << "6. exit : ����" << std::endl;

	std::cout << std::endl;
}

void ExitCommand::Run()
{
	exit(0);
}