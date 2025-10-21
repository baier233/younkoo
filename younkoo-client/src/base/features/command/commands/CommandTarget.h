#pragma once
#include "../Command.h"
#include <vector>
#include <string>

class CommandTarget : public Command {
public:
	CommandTarget();
	void onCommand(std::string msg);
	static CommandTarget& getInstance();
private:
	void insertContent(const std::string& filename, const std::string& newContent, int lineNumber);
	bool containsContent(const std::string& filename, const std::string& content);
	void appendContent(const std::string& filename, const std::string& newContent);
	void deleteContent(const std::string& filename, const std::string& contentToDelete);
};
