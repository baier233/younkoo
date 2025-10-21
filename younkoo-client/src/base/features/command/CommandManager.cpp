#include "CommandManager.h"
#include <iostream>
#include "Command.h"

#include "commands/CommandTarget.h"

void CommandManager::LoadCommands()
{
	this->addCommand<CommandTarget>(&CommandTarget::getInstance());
}

void CommandManager::executeCommand(std::string str)
{
	for (auto iter = this->commands.cbegin(); iter < this->commands.cend(); iter++) {
		Command* cmd = reinterpret_cast<Command*>(*iter);
		for (std::string command : cmd->getCommands()) {
			if (str.find(' ') != std::string::npos) {
				std::string commandPart = str.substr(0, str.find(' '));
				if (commandPart == command) {
					cmd->onCommand(str);
				}
			}
			else {
				if (command == str) {
					cmd->onCommand(str);
				}
			}
		}
	}
}
