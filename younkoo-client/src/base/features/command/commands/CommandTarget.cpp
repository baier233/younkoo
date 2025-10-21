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

	// ��ȡ�ļ�����
	if (inputFile.is_open()) {
		while (std::getline(inputFile, line)) {
			lines.push_back(line);
		}
		inputFile.close();
	}
	else {
		std::cerr << "�޷����ļ�" << std::endl;
		return;
	}

	// ��ָ���в���������
	if (lineNumber >= 0 && lineNumber <= lines.size()) {
		lines.insert(lines.begin() + lineNumber, newContent);
	}
	else {
		std::cerr << "�кų�����Χ" << std::endl;
		return;
	}

	// ������д���ļ�
	std::ofstream outputFile(filename);
	if (outputFile.is_open()) {
		for (const auto& l : lines) {
			outputFile << l << std::endl;
		}
		outputFile.close();
	}
	else {
		std::cerr << "�޷�д���ļ�" << std::endl;
	}
}

bool CommandTarget::containsContent(const std::string& filename, const std::string& content)
{
	std::ifstream inputFile(filename);
	std::string line;

	// ����ļ��Ƿ�����ض�����
	if (inputFile.is_open()) {
		while (std::getline(inputFile, line)) {
			if (line == content) {
				inputFile.close();
				return true; // �ҵ�����
			}
		}
		inputFile.close();
	}
	else {
		std::cerr << "�޷����ļ�" << std::endl;
	}
	return false; // δ�ҵ�����
}

void CommandTarget::appendContent(const std::string& filename, const std::string& newContent)
{
	std::ofstream outputFile(filename, std::ios::app); // �Ը���ģʽ���ļ�

	if (outputFile.is_open()) {
		outputFile << newContent << std::endl; // ��������ݺͻ���
		outputFile.close();
	}
	else {
		std::cerr << "�޷�д���ļ�" << std::endl;
	}
}

void CommandTarget::deleteContent(const std::string& filename, const std::string& contentToDelete)
{
	std::ifstream inputFile(filename);
	std::vector<std::string> lines;
	std::string line;

	// ��ȡ�ļ�����
	if (inputFile.is_open()) {
		while (std::getline(inputFile, line)) {
			lines.push_back(line);
		}
		inputFile.close();
	}
	else {
		std::cerr << "�޷����ļ�" << std::endl;
		return;
	}

	// ɾ��ָ������
	lines.erase(std::remove_if(lines.begin(), lines.end(),
		[&](const std::string& l) { return l == contentToDelete; }),
		lines.end());

	// �����º������д���ļ�
	std::ofstream outputFile(filename);
	if (outputFile.is_open()) {
		for (const auto& l : lines) {
			outputFile << l << std::endl;
		}
		outputFile.close();
	}
	else {
		std::cerr << "�޷�д���ļ�" << std::endl;
	}
}

