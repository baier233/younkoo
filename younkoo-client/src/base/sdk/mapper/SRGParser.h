#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <gzip/decompress.hpp>
#pragma comment(lib, "zlibstat.lib")
enum class Versions {
	MCP_1_8_9,
	MCP_1_12_2,
	MCP_1_18_1,
	FORGE_1_8_9,
	FORGE_1_12_2,
	FORGE_1_18_1,
	FORGE_1_20_1,
	LUNAR_1_8_9,
	LUNAR_1_12_2,
	FABRIC_1_20_4
};

#include "../../../utils/Singleton.hpp"
class SRGParser : public Singleton<SRGParser> {
private:
	Versions version;
	std::unordered_map<std::string, std::string> fieldMappings;
	std::unordered_map<std::string, std::pair<std::string, std::string>> methodMappings;
	std::unordered_map<std::string, std::string> classMappings;

	void Init(const unsigned char* srgBytes, size_t size, bool Reverse, bool compressed);
public:

	void SetVersion(Versions ver);
	Versions GetVersion() const;

	std::string getObfuscatedFieldName(const std::string& originalClassName, const std::string& originalFieldName);
	//return obfuscated method name and description
	std::pair<std::string, std::string> getObfuscatedMethodName(const std::string& originalClassName, const std::string& originalMethodName, const std::string& methodDesc);
	std::string getObfuscatedClassName(const std::string& originalClassName);
};