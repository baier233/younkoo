#include "ModuleInfo.h"
#include <base\render\nano\NanovgHelper.hpp>
#include <utils/Wstr.h>
#include <base\render\gui\api\VirtualKey.h>
#include "value\BooleanValueComponent.h"
#include "value\FloatValueComponent.h"
#include "value\IntValueComponent.h"
#include "value\ModeValueComponent.h"
#include "value\ColorValueComponent.h"

ModuleInfo::ModuleInfo(AbstractModule* hack)
{
	bindModule = hack;
	toggleAnimation.reset(hack->getToggle() ? 22.9 : 0);


	this->height.reset(73.26 + (hack->getKey() != 0 ? 26 : 0));

	for (auto& valuePair : hack->getValues())
	{
		ValueType valueType = valuePair.first;
		auto& value = valuePair.second;

		switch (valueType)
		{
		case BoolType:
			if (auto boolValue = dynamic_cast<BoolValue*>(value.get()))
			{
				moduleValues.push_back(std::make_shared<BooleanValueComponent>(boolValue));
			}
			break;
		case IntType:
			if (auto intValue = dynamic_cast<NumberValue*>(value.get()))
			{
				moduleValues.push_back(std::make_shared<IntValueComponent>(intValue));
			}
			break;
		case FloatType:
			if (auto floatValue = dynamic_cast<FloatValue*>(value.get()))
			{
				moduleValues.push_back(std::make_shared<FloatValueComponent>(floatValue));
			}
			break;
		case ListType:
			if (auto modeValue = dynamic_cast<ModeValue*>(value.get()))
			{
				moduleValues.push_back(std::make_shared<ModeValueComponent>(modeValue));
			}
			break;
		case ColorType:
			if (auto colorValue = dynamic_cast<ColorValue*>(value.get()))
			{
				moduleValues.push_back(std::make_shared<ColorValueComponent>(colorValue));
			}
			break;
		default:
			break;
		}
	}
}

bool ModuleInfo::mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY, int button)
{
	if (showValues || !this->height.isFinished())
	{
		float test = 0;
		float test1 = ((bindModule->getKey() != 0 || bindingKey) ? 73.26 : 73.26 - 26);
		for (auto& value : moduleValues)
		{
			value->mouseReleased(x, y + test1 + test, width, height, mouseX, mouseY, button);
			test += 26;
		}
	}

	return false;
}

bool ModuleInfo::mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button)
{
	// LEFT CLICK
	if (button == 0 && Component::isHovering(x + width - 116, y + 25 + 30, 42.9, 20.46, mouseX, mouseY))
	{
		bindModule->setToggle(!bindModule->getToggle());
		return true;
	}

	// RIGHT CLICK
	if (button == 1 && Component::isHovering(x + 17, y + 27.72, width - (17 * 2),
		this->height.getCurrent() > 73.26 ? 73.26 : this->height.getCurrent(),
		mouseX, mouseY))
	{
		showValues = !showValues;
		return true;
	}

	if (showValues || !this->height.isFinished())
	{
		float test = 0;
		float test1 = ((bindModule->getKey() != 0 || bindingKey) ? 73.26 : 73.26 - 26);
		for (auto& value : moduleValues)
		{
			value->mouseClicked(x, y + test1 + test, width, height, mouseX, mouseY, button);
			test += 26;
		}
	}

	return false;
}

bool ModuleInfo::mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY,
	double horizontalAmount, double verticalAmount)
{
	return false;
}

void ModuleInfo::draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY)
{
	if (!showValues)
	{
		componentHeight = 100.0F;
	}

	this->height.setTarget(componentHeight);

	this->height.calculate();

	const std::shared_ptr<Scissor> scissor_return_value = NanoVGHelper::scissorHelper.scissor(
		vg, x + 17 - 1, y + 27.72 - 1, width - (17 * 2) + 2,
		this->height.getCurrent() + 2);

	NanoVGHelper::drawRoundedRect(
		vg, x + 17, y + 27.72, width - (17 * 2), this->height.getCurrent(),
		NanoVGHelper::rgbaToColor(255, 255, 255, 255), 5
	);

	NanoVGHelper::drawRoundedOutlineRect(
		vg, x + 17, y + 27.72, width - (17 * 2), this->height.getCurrent(), 5, 1,
		NanoVGHelper::rgbaToColor(227, 227, 227, 255)
	);

	if (bindModule->getKey() != 0 || bindingKey)
	{
		NanoVGHelper::nvgTextW(
			vg, bindingKey ? L"Press a key...." : L"CURRENTLY BOUNDTO: " + VirtualKey::toStringW(bindModule->getKey()),
			x + 17 + 20, y + 27.72 + 44 + 27, NanoVGHelper::fontGreycliffCFLight, 12, nvgRGBA(171, 161, 159, 255)
		);
	}
	else
	{
		NanoVGHelper::nvgTextW(
			vg, bindingKey ? L"Press a key...." : L"CURRENTLY BOUNDTO: NULL",
			x + 17 + 20, y + 27.72 + 44 + 27, NanoVGHelper::fontGreycliffCFLight, 12, nvgRGBA(171, 161, 159, 255)
		);
	}

	if (showValues || !this->height.isFinished())
	{
		float children_height = 0;
		for (const auto& value : moduleValues)
		{
			constexpr float offset_y = 78.0F;
			value->draw(vg, x, y + offset_y + children_height, width, height, mouseX, mouseY);
			children_height += value->component_height_;
		}
		componentHeight = 100.0F + children_height;
	}

	NanoVGHelper::nvgTextW(vg, wstr::toString(bindModule->getName()), x + 17 + 20, y + 27.72 + 22,
		NanoVGHelper::fontHarmony, 17, nvgRGBA(79, 77, 80, 255));

	NanoVGHelper::nvgTextStr(
		vg,
		bindModule->getDesc(),
		x + 17 + 20, y + 27.72 + 44, NanoVGHelper::fontHarmony, 13, nvgRGBA(171, 161, 159, 255)
	);
	// >
	if (bindModule->getValues().size() > 0)
	{

		NanoVGHelper::nvgTextW(
			vg, L"\uEA58",
			x + width - 55, y + 25 + 30, NanoVGHelper::fontMaterialIcon, 21, nvgRGBA(78, 76, 80, 255)
		);
	}

	bool isEnable = bindModule->getToggle();
	toggleAnimation.setTarget(isEnable ? 22.9 : 0);

	toggleAnimation.calculate();


	if (!toggleAnimation.isFinished())
	{
		NanoVGHelper::drawRoundedRect(
			vg, x + width - 116, y + 25 + 30, 42.9, 20.46, NanoVGHelper::rgbaToColor(205, 197, 195, 255), 10
		);

		auto test = NanoVGHelper::scissorHelper.scissor(vg, x + width - 116, y + 25 + 30,
			18 + toggleAnimation.getCurrent(), 20.46);


		NanoVGHelper::drawRoundedRect(
			vg, x + width - 116, y + 25 + 30, 18 + toggleAnimation.getCurrent(), 20.46,
			NanoVGHelper::rgbaToColor(192, 224, 248, 255), 10
		);

		NanoVGHelper::scissorHelper.resetScissor(vg, test);
	}
	else
	{
		NanoVGHelper::drawRoundedRect(
			vg, x + width - 116, y + 25 + 30, 42.9, 20.46,
			isEnable ? NanoVGHelper::rgbaToColor(192, 224, 248, 255) : NanoVGHelper::rgbaToColor(205, 197, 195, 255), 10
		);
	}

	// ENABLE

	NanoVGHelper::drawCircle(
		vg, x + width - 116 + 10 + toggleAnimation.getCurrent(), y + 25 + 30 + 10, 10, -1
	);

	NanoVGHelper::renderShadow(
		vg, x + width - 116 + toggleAnimation.getCurrent(), y + 25 + 30, 20, 20.46, 10, 4
	);

	NanoVGHelper::scissorHelper.resetScissor(vg, scissor_return_value);
}

bool ModuleInfo::keyPressed(int keyCode, int scanCode, int modifiers)
{
	return false;
}
