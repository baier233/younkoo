#include "setting_button.h"

#include "utils/Wstr.h"

setting_button::setting_button(
	std::string title,
	const std::function<void(setting_button& button)>& callback
) : title_(std::move(title)), callback_(callback)
{
	width = 136.0F;
	height = 40.0F;
}

void setting_button::draw(NVGcontext* vg, float x, float y, float width, float height, double mouseX, double mouseY)
{
	NanoVGHelper::drawRoundedRect(
		vg,
		this->x,
		this->y,
		this->width,
		this->height,
		NanoVGHelper::rgbaToColor(42, 129, 255, 255),
		this->height / 2.0F
	);

	const auto title_w = wstr::toString(this->title_);

	const auto [text_width, text_height] = NanoVGHelper::nvgTextBoundsW(
		vg,
		title_w,
		NanoVGHelper::fontHarmony,
		14.0F
	);
	const auto center_x = this->x + (this->width - text_width) / 2.0F;

	NanoVGHelper::nvgTextW(
		vg,
		title_w,
		center_x,
		this->y + 14.0F,
		NanoVGHelper::fontHarmony,
		14.0F,
		nvgRGBA(255, 255, 255, 255)
	);
}

bool setting_button::mouseClicked(float x, float y, float width, float height, double mouseX, double mouseY, int button)
{
	if (isHovering(this->x, this->y, this->width, this->height, mouseX, mouseY))
	{
		callback_(*this);
		return true;
	}
	return false;
}

bool setting_button::mouseReleased(float x, float y, float width, float height, double mouseX, double mouseY,
	int button)
{
	return false;
}

bool setting_button::mouseScrolled(float x, float y, float width, float height, double mouseX, double mouseY,
	double horizontalAmount, double verticalAmount)
{
	return false;
}

bool setting_button::keyPressed(int keyCode, int scanCode, int modifiers)
{
	return false;
}
