#pragma once
#include <map>

class Command
{
public : 
	virtual void Run() = 0;
};

class ShowFileCommand : public Command
{
public : 
	virtual void Run() override;
};

class ChangeDirectoryCommand : public Command
{
public : 
	virtual void Run() override;
};

class MakeDirectoryCommand : public Command
{
public:
	virtual void Run() override;
};

class MakeFileCommand : public Command
{
public:
	virtual void Run() override;
};

class ShowCommandList : public Command
{
public:
	virtual void Run() override;
};

class ExitCommand : public Command
{
public : 
	virtual void Run() override;
};