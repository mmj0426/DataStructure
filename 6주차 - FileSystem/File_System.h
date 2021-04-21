#pragma once
#include "Node.h"
#include <iostream>

class File_System
{
public : 
	static File_System* GetInstance()
	{
		if (nullptr == instance)
		{
			instance = new File_System();
		}
		return instance;
	}


private:
	File_System()
	{
		root = new Node("/", true, {});
		currentDirectory = root;
	}
	~File_System()
	{
		delete root;
		delete currentDirectory;
	}

	static File_System* instance;

public : 
	Node* find(const std::string& path)
	{
		if (path[0] == '/')
		{
			return find_impl(root,path.substr(1));
		}
		else
		{
			return find_impl(currentDirectory, path);
		}
	}

	bool add(const std::string& path, bool isDir)
	{
		if (path[0] == '/')
		{
			return add_impl(root,path.substr(1),isDir);
		}
		else
		{
			return add_impl(currentDirectory,path,isDir);
		}
	}

	void SetCurrentDirectory(Node* _currentDirectory){currentDirectory = _currentDirectory;}
	Node* GetCurrentDirectory(){return currentDirectory;}

private : 
	Node* find_impl(Node* directory, const std::string& path)
	{
		if (path.empty())
		{
			return directory;
		}
		auto separate = path.find('/');

		std::string current_path = separate == std::string::npos ? path : path.substr(0,separate);

		std::string rest_path = separate == std::string::npos ? "" : path.substr(separate+1);

		auto found = std::find_if(directory->children.begin(),directory->children.end(),
			[&](const Node* child)
			{
				return child->name == current_path;
			});

		if (found != directory->children.end())
		{
			return find_impl(*found, rest_path);
		}
		return nullptr;
	}

	bool add_impl(Node* directory, const std::string& path, bool isDir)
	{
		if (!directory->isDir)
		{
			std::cout << directory->name << "은(는) 파일입니다." << std::endl;
			return false;
		}

		auto separate = path.find('/');

		if (separate == std::string::npos)
		{
			auto found = std::find_if(directory->children.begin(), directory->children.end(),
				[&](const Node* child)
				{
					return child->name == path;
				});

			if (found != directory->children.end())
			{
				std::cout << directory->name << "에 이미 " << path << "이름의 파일/디렉토리가 있습니다." << std::endl;
				return false;
			}

			directory->children.push_back(new Node{ path,isDir,{} });
			return true;
		}

		std::string next_dir = path.substr(0,separate);

		auto found = std::find_if(directory->children.begin(), directory->children.end(), 
			[&](const Node* child) 
			{
				return child->name == next_dir && child->isDir;
			});

		if (found != directory->children.end())
		{
			return add_impl(*found, path.substr(separate + 1), isDir);
		}

		std::cout << directory->name << "에 " << next_dir << " 이름의 디렉토리가 없습니다." << std::endl;

		return false;
	}

private : 
	Node* root;
	Node* currentDirectory;
};

