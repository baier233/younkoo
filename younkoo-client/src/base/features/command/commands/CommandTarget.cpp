#include "CommandTarget.h"
#include <iostream>
#include <wrapper/net/minecraft/client/Minecraft.h>
#include "../config/ConfigManager.h"
CommandTarget::CommandTarget() : Command({ "traget","t" })
{
	this->setArgs(".target add/remove id");
}

void CommandTarget::onCommand(std::string msg)
{
	auto path = ConfigManager::get().GetConfigPath() / "targets.txt";
	std::ifstream file(path);
	if (!file.good())
	{
		std::ofstream file(ConfigManager::get().GetConfigPath() / "targets.txt");
		file << "";
		file.close();
	}

	std::istringstream stream(msg);
	std::string word;
	std::vector<std::string> words;

	while (stream >> word) {
		words.push_back(word);
	}
	if (words.size() < 2)
	{
		MessageBox(NULL, L"Usage: .target add/remove id", L"Error", MB_OK);
		return;
	}
	if (words[1] == "add") {
		if (!this->containsContent(path.string(), words[2]));
		{
			this->appendContent(path.string(), words[2]);
		}
	}
	else if (words[1] == "remove") {
		if (this->containsContent(path.string(), words[2]))
		{
			this->deleteContent(path.string(), words[2]);
		}
	}
}

CommandTarget& CommandTarget::getInstance()
{
	static CommandTarget instance;
	return instance;
}

void CommandTarget::insertContent(const std::string& filename, const std::string& newContent, int lineNumber)
{
	std::ifstream inputFile(filename);
	std::vector<std::string> lines;
	std::string line;

	// 读取文件内容
	if (inputFile.is_open()) {
		while (std::getline(inputFile, line)) {
			lines.push_back(line);
		}
		inputFile.close();
	}
	else {
		std::cerr << "无法打开文件" << std::endl;
		return;
	}

	// 在指定行插入新内容
	if (lineNumber >= 0 && lineNumber <= lines.size()) {
		lines.insert(lines.begin() + lineNumber, newContent);
	}
	else {
		std::cerr << "行号超出范围" << std::endl;
		return;
	}

	// 将内容写回文件
	std::ofstream outputFile(filename);
	if (outputFile.is_open()) {
		for (const auto& l : lines) {
			outputFile << l << std::endl;
		}
		outputFile.close();
	}
	else {
		std::cerr << "无法写入文件" << std::endl;
	}
}

bool CommandTarget::containsContent(const std::string& filename, const std::string& content)
{
	std::ifstream inputFile(filename);
	std::string line;

	// 检查文件是否包含特定内容
	if (inputFile.is_open()) {
		while (std::getline(inputFile, line)) {
			if (line == content) {
				inputFile.close();
				return true; // 找到内容
			}
		}
		inputFile.close();
	}
	else {
		std::cerr << "无法打开文件" << std::endl;
	}
	return false; // 未找到内容
}

void CommandTarget::appendContent(const std::string& filename, const std::string& newContent)
{
	std::ofstream outputFile(filename, std::ios::app); // 以附加模式打开文件

	if (outputFile.is_open()) {
		outputFile << newContent << std::endl; // 添加新内容和换行
		outputFile.close();
	}
	else {
		std::cerr << "无法写入文件" << std::endl;
	}
}

void CommandTarget::deleteContent(const std::string& filename, const std::string& contentToDelete)
{
	std::ifstream inputFile(filename);
	std::vector<std::string> lines;
	std::string line;

	// 读取文件内容
	if (inputFile.is_open()) {
		while (std::getline(inputFile, line)) {
			lines.push_back(line);
		}
		inputFile.close();
	}
	else {
		std::cerr << "无法打开文件" << std::endl;
		return;
	}

	// 删除指定内容
	lines.erase(std::remove_if(lines.begin(), lines.end(),
		[&](const std::string& l) { return l == contentToDelete; }),
		lines.end());

	// 将更新后的内容写回文件
	std::ofstream outputFile(filename);
	if (outputFile.is_open()) {
		for (const auto& l : lines) {
			outputFile << l << std::endl;
		}
		outputFile.close();
	}
	else {
		std::cerr << "无法写入文件" << std::endl;
	}
}

