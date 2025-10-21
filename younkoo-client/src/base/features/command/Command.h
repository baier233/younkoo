#pragma once
#include <vector>
#include <string>
class Command {
public:
	Command(std::vector<std::string> commands);
	void setArgs(std::string args);
	std::string getArgs();
	std::vector<std::string> getCommands();
	virtual void onCommand(std::string msg) = 0;

	virtual ~Command() = default;
	Command(Command&&) = delete;
	Command(const Command&) = delete;
	Command& operator=(const Command&) = delete;
private:
	std::vector<std::string> commands;
	std::string args;
};