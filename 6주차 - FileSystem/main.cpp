#include "File_System.h"
#include "Commands.h"

int main()
{
	std::map<std::string, Command*> commands;
	commands.insert(std::make_pair("ls", new ShowFileCommand()));
	commands.insert(std::make_pair("cd", new ChangeDirectoryCommand()));
	commands.insert(std::make_pair("mkdir", new MakeDirectoryCommand()));
	commands.insert(std::make_pair("vi", new MakeFileCommand()));
	commands.insert(std::make_pair("exit", new ExitCommand()));
	commands.insert(std::make_pair("help", new ShowCommandList()));

	File_System::GetInstance()->add("usr", true);
	File_System::GetInstance()->add("etc", true);
	File_System::GetInstance()->add("var", true);
	File_System::GetInstance()->add("temp_file", false);

	std::string input_cmd;

	while (true)
	{
		std::cout << ">";
		std::cin >> input_cmd;

		if (commands.find(input_cmd) != commands.end())
		{
			commands[input_cmd]->Run();
		}
	}

	return 0;

}