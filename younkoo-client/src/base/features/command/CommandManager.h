#pragma once
#include <vector>
#include <string>
#include "..\..\..\utils\Singleton.hpp"
class CommandManager :public Singleton<CommandManager> {
private:
	std::vector<void*> commands;
public:
	void LoadCommands();
	void executeCommand(std::string str);

	template<class CommandCLASS>
	void addCommand(CommandCLASS* cmd);

};

template<class CommandCLASS>
inline void CommandManager::addCommand(CommandCLASS* cmd)
{
	this->commands.push_back(reinterpret_cast<void*>(cmd));
}
