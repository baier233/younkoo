#include "AutoClicker.h"

#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <optional>
#include <random>
#include <wrapper/net/minecraft/item/ItemBlock.h>
#include <wrapper/net/minecraft/item/ItemBow.h>

#include <base/render/gui/input/InputApi.h>
#include <base/features/api/ClickApi.h>
namespace Left {

	long lastClickTime = 0;
	long startTime = 0;
	int nextCps = 10;
	int count = 0;
	bool shouldPress = true;
	static int minAps = 10;
	static int maxAps = 10;
}

namespace Right {

	long lastClickTime = 0;
	int nextCps = 10;
	int count = 0;
	static int minAps = 10;
	static int maxAps = 10;
}


AutoClicker::AutoClicker() :AbstractModule(xorstr_("AutoClicker"), Category::COMBAT, xorstr_("Auto Clicker."), 'U')
{
	this->setToggle(false);

	this->addValue(FloatType, leftMinCpsValue);
	this->addValue(FloatType, leftMaxCpsValue);

	this->addValue(BoolType, blockHitValue);
	this->addValue(FloatType, blockHitChanceValue);

	this->addValue(BoolType, doubleClickValue);
	this->addValue(BoolType, doubleClickMistakeValue);
	this->addValue(FloatType, doubleClickChanceValue);

	this->addValue(BoolType, miningValue);
	this->addValue(BoolType, inInventoryValue);
	this->addValue(BoolType, blockOnlyValue);
	this->addValue(BoolType, ignoreBowValue);

	this->addValue(ListType, clickModeValue);
}

#include <base/features/api/ClickApi.h>
AutoClicker& AutoClicker::getInstance()
{
	static AutoClicker instance = AutoClicker();
	return instance;
}

void AutoClicker::onEnable()
{
	LOG("Attack Key:" << Wrapper::Minecraft::getMinecraft().getSettings().getAttackKey() << " Use Key :" <<
		Wrapper::Minecraft::getMinecraft().getSettings().getUseKey());
}

void AutoClicker::onDisable()
{

}
static bool blockState = false;
using namespace InputApi;
using namespace ClickApi;
void AutoClicker::onUpdate()
{
	ToggleCheck;
	if (NanoGui::available) return;
	if (Wrapper::Minecraft::getMinecraft().isInGuiState() && !inInventoryValue->getValue()) return;

	static auto getClickMode = [](ClickMode mode) -> std::optional<std::pair<bool, bool>> {
		switch (mode) {
		case BOTH:
			return std::make_pair(true, true);
		case LEFTONLY:
			return std::make_pair(true, false);
		case RIGHTONLY:
			return std::make_pair(false, true);
		default:
			return std::nullopt;
		}
		};

	auto [left, right] = getClickMode(static_cast<ClickMode>(clickModeValue->getValue())).value_or(std::make_pair(false, false));
	const auto handleWindow = Renderer::get().renderContext.HandleWindow;

	auto mc = Wrapper::Minecraft::getMinecraft();

	while (left)
	{
		long milli = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		if (Left::lastClickTime == 0) Left::lastClickTime = milli;
		if ((milli - Left::lastClickTime) < (1000 / Left::nextCps)) break;
		if (true || Younkoo::get().info.major <= MajorVersion::MAJOR_112)
		{
			if (!GetAsyncKeyState(VK_LBUTTON) && 1) break;
		}
		else {

			if (!(inputContext.IsMousePressed(ClickApi::keyAttack))) break;
		}

		auto mouseOver = mc.getMouseOver();

		POINT pos_cursor;
		GetCursorPos(&pos_cursor);
		static auto updateCps = [&] {

			Left::lastClickTime = milli;
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> distrib(((int)leftMinCpsValue->getValue()), ((int)leftMaxCpsValue->getValue()));
			Left::nextCps = distrib(gen);

			};

		if (miningValue->getValue() && !mouseOver.isNULL() && mouseOver.isTypeOfBlock()) {

			if (!blockState)
			{
				GenricMCClick(MouseType::LEFT, ClickType::DOWN);
				updateCps();
				blockState = true;
			}
			break;
		}
		blockState = false;

		if (doubleClickValue->getValue())
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> distrib(0, 100);
			bool shouldDoubleClick = distrib(gen) <= doubleClickChanceValue->getValue();
			if (Left::shouldPress)
			{
				GenricMCClick(MouseType::LEFT, ClickType::DOWN);
				GenricMCClick(MouseType::LEFT, ClickType::UP);
				if (shouldDoubleClick)
				{
					GenricMCClick(MouseType::LEFT, ClickType::DOWN);
					GenricMCClick(MouseType::LEFT, ClickType::UP);
				}
				Left::shouldPress = (doubleClickMistakeValue->getValue() && !shouldDoubleClick) ? false : (!shouldDoubleClick);
			}
			else {
				Left::shouldPress = true;
			}
		}
		else {
			GenricMCClick(MouseType::LEFT, ClickType::DOWN);
			GenricMCClick(MouseType::LEFT, ClickType::UP);
		}

		if (blockHitValue->getValue() == true && Left::count == blockHitChanceValue->getValue()) {
			GenricMCClick(MouseType::RIGHT, ClickType::DOWN);
			GenricMCClick(MouseType::RIGHT, ClickType::UP);
			Left::count = 0;
		}

		else if (blockHitValue->getValue() == true) {
			Left::count++;
		}
		updateCps();
		break;

	}

	if (right)
	{
		const long milli = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		if (Right::lastClickTime == 0) Right::lastClickTime = milli;
		if ((milli - Right::lastClickTime) < (1000 / Right::nextCps)) return;

		if (inputContext.IsMousePressed(ClickApi::keyUse)) {

			if (Younkoo::get().info.major >= MajorVersion::MAJOR_1181)
			{
				auto itemStack = mc.getPlayer().getInventory().getCurrentItem();
				if (itemStack.isNULL()) return;
				auto mainItem = itemStack.getItem();
				if (mainItem.isNULL()) return;
				auto offitemStack = mc.getPlayer().getOffhandItemStack();
				if (offitemStack.isNULL()) return;
				auto offItem = offitemStack.getItem();
				if (offItem.isNULL()) return;

				if (blockOnlyValue->getValue() && !(JNI::get_env()->IsInstanceOf(mainItem.getObject(), Wrapper::ItemBlock::klass()) || JNI::get_env()->IsInstanceOf(offItem.getObject(), Wrapper::ItemBlock::klass()))) return;

				if (ignoreBowValue->getValue() && (JNI::get_env()->IsInstanceOf(mainItem.getObject(), Wrapper::ItemBow::klass()) || JNI::get_env()->IsInstanceOf(offItem.getObject(), Wrapper::ItemBow::klass()))) return;
			}
			else {
				auto itemStack = mc.getPlayer().getInventory().getCurrentItem();
				if (itemStack.isNULL()) return;
				auto mainItem = itemStack.getItem();
				if (mainItem.isNULL()) return;
				if (blockOnlyValue->getValue() && !(JNI::get_env()->IsInstanceOf(mainItem.getObject(), Wrapper::ItemBlock::klass()))) return;

				if (ignoreBowValue->getValue() && (JNI::get_env()->IsInstanceOf(mainItem.getObject(), Wrapper::ItemBow::klass()))) return;

			}



			POINT pos_cursor;

			GetCursorPos(&pos_cursor);
			GenricMCClick(MouseType::RIGHT, ClickType::DOWN);
			GenricMCClick(MouseType::RIGHT, ClickType::UP);

			Right::lastClickTime = milli;

			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> distrib(this->rightMinCpsValue->getValue(), this->rightMaxCpsValue->getValue());
			Right::nextCps = distrib(gen);
		}
	}

}