#pragma once
#include <string>
namespace VirtualKey {
	std::string toString(int key);
	std::wstring toStringW(int key);
}

int getKeyMods();
