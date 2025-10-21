#pragma once
#include <string>
#include <windows.h>
#include "..\values\Value.h"
#include "../../event/EventBus.hpp"

#include <memory>

#define IsKeyBeingDown(KEYNONAME) ((GetAsyncKeyState(KEYNONAME)&0x8000)?1:0)

#define REGISTER_EVENT(eventType, callbackFunction) \
    ModuleManager::get().registrations.push_back(Younkoo::get().EventBus->register_handler<eventType>(this, &callbackFunction))
#define ToggleCheck if (!this->getToggle()) return
#define DefaultConstructor(_Class) _Class() = default
#define DefaultDeconstructor(_Class) ~_Class() = default
#define NoMoveConstructor(_Class) _Class(_Class&&) = delete
#define NoCopyConstructor(_Class) _Class(const _Class&) = delete
#define NoAssignOperator(_Class) _Class& operator=(const _Class&) = delete

enum class Category : unsigned int {
	COMBAT = 0,
	MOVEMENT,
	PLAYER,
	VISUAL,
	WORLD,
	SETTING
};

inline std::string getCategoryName(Category category) {
	switch (category) {
	case Category::COMBAT:
		return "COMBAT";
	case Category::MOVEMENT:
		return "MOVEMENT";
	case Category::PLAYER:
		return "PLAYER";
	case Category::WORLD:
		return "WORLD";
	case Category::VISUAL:
		return "VISUAL";
	case Category::SETTING:
		return "SETTING";
	default:
		return "UNKNOWN";
	}
}

inline std::wstring getCategoryDisplayName(Category category) {
	switch (category) {
	case Category::COMBAT:
		return L"Combat";
	case Category::MOVEMENT:
		return L"Movement";
	case Category::PLAYER:
		return L"Player";
	case Category::WORLD:
		return L"World";
	case Category::VISUAL:
		return L"Visual";
	case Category::SETTING:
		return L"Setting";
	default:
		return L"UNKNOWN";
	}
}

inline std::wstring getCategoryIcon(Category category) {
	switch (category) {
	case Category::COMBAT:
		return L"\uE9DB";
	case Category::MOVEMENT:
		return L"\uEB34";
	case Category::PLAYER:
		return L"\uEBAD";
	case Category::WORLD:
		return L"\uEBB1";
	case Category::VISUAL:
		return L"\uEAE1";
	case Category::SETTING:
		return L"\uEBB1";
	default:
		return L"UNKNOWN";
	}
}

class AbstractModule {
protected:
	std::vector<std::pair<ValueType, std::shared_ptr<Value>>> values;
private:

	std::string name;
	std::string desc;
	int key = 0;
	Category category;
	bool i_toggle;
public:

	inline void addValue(ValueType type, const std::shared_ptr<Value>& value)
	{
		values.push_back(std::pair<ValueType, std::shared_ptr<Value>>(type, value));
	}

	inline std::vector<std::pair<ValueType, std::shared_ptr<Value>>> getValues() {
		return values;
	}

	inline std::shared_ptr<Value> getValueObjByName(const std::string& name) {
		for (int i = 0; i < values.size(); i++)
		{
			auto crtObj = values[i].second;
			if (name.compare(crtObj->getName()) == 0)
			{
				return crtObj;
			}
		}
	}

	void toggle();

	void onToggled();

	std::string getName();

	std::string getDesc();

	bool getToggle();

	void setToggle(bool _NEW);

	void enable();

	void disable();

	int& getKey();

	void setKeyCode(int keycode);

	void onKeyEvent(int key);

	Category getCategory();

	virtual void onEnable() = 0;

	virtual void onDisable() = 0;

	virtual void onUpdate() = 0;

	//virtual void RenderMenu() = 0;

	AbstractModule(const char* ModName, Category Modcategory);
	AbstractModule(const char* ModName, Category Modcategory, std::string desc);
	AbstractModule(const char* ModName, Category Modcategory, int k);
	AbstractModule(const char* ModName, Category Modcategory, std::string desc, int k);

	virtual ~AbstractModule() = default;

	AbstractModule(AbstractModule&&) = delete;

	AbstractModule(const AbstractModule&) = delete;

	AbstractModule& operator=(const AbstractModule&) = delete;
};
































