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
		std::cout << path << " 경로가 존재하지 않습니다." << std::endl;
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

	std::cout << "변경 디렉토리 이름 > ";
	std::cin >> changeDirectoryName;

	auto found = File_System::GetInstance()->find(changeDirectoryName);
	if (found && found->isDir)
	{
		File_System::GetInstance()->SetCurrentDirectory(found);
		std::cout << "현재 디렉토리를 "<< File_System::GetInstance()->GetCurrentDirectory()->name << "로 이동합니다." << std::endl << std::endl;
		return;
	}

	std::cout << changeDirectoryName << "경로를 찾을 수 없습니다." << std::endl;
	return;

	std::cout<<std::endl;
}

void MakeDirectoryCommand::Run()
{
	std::string newDirectoryName;

	std::cout << "생성 디렉토리 이름 > ";
	std::cin >> newDirectoryName;

	File_System::GetInstance()->add(newDirectoryName,true);
	std::cout << std::endl;
}

void MakeFileCommand::Run()
{
	std::string newFileName;

	std::cout << "생성 파일 이름 > ";
	std::cin >> newFileName;

	File_System::GetInstance()->add(newFileName,false);
	std::cout << std::endl;
}

void ShowCommandList::Run() 
{
	std::cout << "<명령어 목록>" << std::endl;
	std::cout << "1. ls : 현재 디렉토리에 포함된 디렉토리, 파일 출력" << std::endl;
	std::cout << "2. cd : 현재 디렉토리 변경" << std::endl;
	std::cout << "3. mkdir : 디렉토리 생성" << std::endl;
	std::cout << "4. pwd : 현재 경로 출력" << std::endl;
	std::cout << "5. vi : 파일 생성" << std::endl;
	std::cout << "6. exit : 종료" << std::endl;

	std::cout << std::endl;
}

void ExitCommand::Run()
{
	exit(0);
}