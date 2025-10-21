#include "Command.h"

Command::Command(std::vector<std::string> commands) :commands(commands)
{
}

void Command::setArgs(std::string args)
{
	this->args = args;
}

std::string Command::getArgs()
{
	return this->args;
}

std::vector<std::string> Command::getCommands()
{
	return this->commands;
}
