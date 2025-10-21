#include "ESP.h"

#include "../ModuleManager.h"
#include <wrapper/net/minecraft/client/Minecraft.h>
#include <wrapper/net/minecraft/client/renderer/ActiveRenderInfo.h>
#include <base/render/gui/GUI.h>
#include <base/render/Renderer.hpp>

#include <base/features/modules/common/CommonData.h>

#include <vector>
#include <map>
#include <ranges>
#include <array>

#include <format>
#include <utils/Misc.hpp>
#include <base/features/modules/player/AntiBot.h>
#include <concurrent_vector.h>

static std::array<int, 4> viewport{};

static std::vector<EntityData> entitiesToRender[2]{ {},{} };
static int currentBufferIndex = 0;

ESP::ESP() : AbstractModule(xorstr_("ESP"), Category::VISUAL) {
	REGISTER_EVENT(EventRender3D, ESP::onRender3D);
	REGISTER_EVENT(EventRender2D, ESP::onRender);
	this->addValue(BoolType, teamBasedColorValue);
	this->addValue(BoolType, Newstyle);
	this->addValue(BoolType, HealthBar);
	this->addValue(FloatType, outlineWidth);
	this->addValue(FloatType, RGB_R);
	this->addValue(FloatType, RGB_G);
	this->addValue(FloatType, RGB_B);
}

ESP& ESP::getInstance() {
	static ESP instance;
	return instance;
}

void ESP::onEnable() {}

void ESP::onDisable() {}
struct Data {
	std::vector<Math::Vector3D> boxVerticies;
	float dist;
	float opacityFadeFactor;
	float health;
	float maxHealth;
};

static std::vector<Data> renderData;
std::mutex vectorMutex;

void ESP::onUpdate() {
	ToggleCheck;
	if (Younkoo::get().info.major == MajorVersion::MAJOR_189 or Younkoo::get().info.major == MajorVersion::MAJOR_112) {
		Wrapper::Minecraft mc = Wrapper::Minecraft::getMinecraft();
		if (!mc.getObject()) return;
		Wrapper::EntityPlayerSP player = mc.getPlayer();
		if (!player.getObject()) return;

		Math::Vector3D renderPos = CommonData::get().renderPos;
		Math::Vector3D pos = player.getPosition();

		if (CommonData::get().thirdPersonView != 0) {
			auto angles = player.getAngles();
			float distance = 8;
			if (CommonData::get().thirdPersonView == 2)
				distance = -distance;
			float cos = std::cos(Math::degToRadiants(angles.yRot + 90.0f));
			float sin = std::sin(Math::degToRadiants(angles.yRot + 90.0f));
			float cosPitch = std::cos(Math::degToRadiants(angles.xRot));
			float sinPitch = std::sin(Math::degToRadiants(angles.xRot));

			float x = renderPos.x - (cos * distance * cosPitch);
			float y = renderPos.y + (distance * sinPitch);
			float z = renderPos.z - (sin * distance * cosPitch);

			renderPos = Math::Vector3D{ x,y,z };
		}
		std::vector<Data> newData;

		auto list = mc.getWorld().getPlayerList();
		float renderPartialTicks = CommonData::get().renderPartialTicks;
		//LOG("renderPartialTicks :" << renderPartialTicks);
		//LOG("renderPos { X:" << renderPos.x << " Y:" << renderPos.y << " Z:" << renderPos.z << " }");

		for (Wrapper::EntityPlayer entity : list)
		{
			if (mc.getPlayer().isEqualTo(entity)) continue;
			if (!entity.getObject() || entity.isNULL()) continue;


			if (Antibot::getInstance().getToggle() && Antibot::getInstance().isBot(entity)) {
				continue;
			}
			auto entityPos = entity.getPosition();
			auto entityLastPos = entity.getLastTickPos();
			//LOG("entityPos { X:" << entityPos.x << " Y:" << entityPos.y << " Z:" << entityPos.z << " }");
			//LOG("entityLastPos { X:" << entityLastPos.x << " Y:" << entityLastPos.y << " Z:" << entityLastPos.z << " }");

			float entityWidth = 0.7f;
			float entityHeight = (float)(entity.getHeight() / 2) + 0.2f;


			auto diff = pos - entityPos;
			float dist = sqrt(pow(diff.x, 2) + pow(diff.y, 2) + pow(diff.z, 2)); // Sqrt((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2)
			// Regular distance check.
			if (dist > 300) {
				continue;
			}

			// You can't put one vector3 for fixing the jittering and use that to subtract all of them with it
			// it will mess screw up for some weird reason. Try it for yourself if you wish!
			//Vector3 fixedEntityPos{ entityLastPos + (entityLastPos - entityPos) * renderPartialTicks };

			// This stops the jittering, the calculations must be inverted for some reason from the original
			Math::Vector3D origin{ renderPos - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks }; // At the feet

			// Same with the offset of the point, it must be offset from the render position, not the entity position for some weird reason.
			Math::Vector3D top{ (renderPos - Math::Vector3D{0, entityHeight * 2, 0}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks }; // Over the head
			Math::Vector3D left{ (renderPos - Math::Vector3D{entityWidth, entityHeight, 0}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks }; // In the middle to the left
			Math::Vector3D right{ (renderPos - Math::Vector3D{-entityWidth, entityHeight, 0}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks }; // In the middle to the right
			Math::Vector3D back{ (renderPos - Math::Vector3D{0, entityHeight, entityWidth}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks }; // In the middle to the back
			Math::Vector3D front{ (renderPos - Math::Vector3D{0, entityHeight, -entityWidth}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks }; // And in the middle to the front

			entityWidth /= 1.388888;
			Math::Vector3D left2{ (renderPos - Math::Vector3D{entityWidth, entityHeight, entityWidth}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks }; // In the middle to the left
			Math::Vector3D right2{ (renderPos - Math::Vector3D{-entityWidth, entityHeight, -entityWidth}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks }; // In the middle to the right
			Math::Vector3D back2{ (renderPos - Math::Vector3D{-entityWidth, entityHeight, entityWidth}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks }; // In the middle to the back
			Math::Vector3D front2{ (renderPos - Math::Vector3D{entityWidth, entityHeight, -entityWidth}) - entityLastPos + (entityLastPos - entityPos) * renderPartialTicks }; // And in the middle to the front

			// ^ This shapes a diamond like formation which results in 6 world to screens instead of 8.
			// However if a 3d ESP is desired, 8 world to screens would be required.

			// Another note for this data, is we cannot use the bounding box values because it can be changed by the reach module, so its best we make our own values with the cost
			// of consuming a little bit of resources for a bit of math.
			std::vector<Math::Vector3D> boxVerticies{
				origin, top, left, right, back, front, left2, right2,back2, front2
			};

			// For when the player gets close to an entity, a fade factor; a value between 0 and 1, with basic math, can get a cool looking fade effect if the player is too close
			// or inside the FadeDistance radius.
			float fadeFactor = 1.0f;
			if ((dist - 1) <= 3.f)
				fadeFactor = ((dist - 1) / 3.f);

			// To render the distance value under the ESP box.
			char distC[32];
			std::snprintf(distC, sizeof(distC), "%.1f", dist);
			std::string distS(distC);

			// Then finally taking all the data we acquired for this loop and pushing it to the data list.
			newData.push_back(Data{
				.boxVerticies = boxVerticies, // Box data
				.dist = dist, // Real distance value (for fade)
				.opacityFadeFactor  = fadeFactor, // Fade factor
				.health = entity.getHealth(), // Entity health
				.maxHealth = entity.getMaxHealth(), // And max health (for health bar)
				});
		}

		std::lock_guard<std::mutex> lock(vectorMutex);
		renderData = newData;
	}
}

#include <utils/Wstr.h>
#include <utils/strutils.h>

static std::map<wchar_t, NVGcolor> colorMap = {
	{'0', nvgRGBA(0, 0, 0, 255)},         // "black"
	{'1', nvgRGBA(0, 0, 139, 255)},       // "dark_blue"
	{'2', nvgRGBA(0, 139, 139, 255)},     // "dark_aqua"
	{'3', nvgRGBA(0, 206, 209, 255)},     // "dark_aqua"
	{'4', nvgRGBA(139, 0, 0, 255)},       // "dark_red"
	{'5', nvgRGBA(139, 0, 139, 255)},     // "dark_purple"
	{'6', nvgRGBA(255, 215, 0, 255)},     // "gold"
	{'7', nvgRGBA(169, 169, 169, 255)},   // "gray"
	{'8', nvgRGBA(105, 105, 105, 255)},   // "dark_gray"
	{'9', nvgRGBA(0, 0, 255, 255)},       // "blue"
	{'a', nvgRGBA(0, 255, 0, 255)},       // "green"
	{'b', nvgRGBA(0, 255, 255, 255)},     // "aqua"
	{'c', nvgRGBA(255, 0, 0, 255)},       // "red"
	{'d', nvgRGBA(255, 182, 193, 255)},   // "light_purple"
	{'e', nvgRGBA(255, 255, 0, 255)},     // "yellow"
	{'f', nvgRGBA(255, 255, 255, 255)}    // "white"
};
	
static std::pair<std::wstring, NVGcolor> parseName(const std::wstring& name) {
	if (strutil::starts_with(name, L"红队 |")) {
		return std::make_pair(name.substr(5), nvgRGBA(255, 69, 69, 255));
	}
	else if (strutil::starts_with(name, L"蓝队 |")) {
		return std::make_pair(name.substr(5), nvgRGBA(70, 130, 180, 255));
	}
	else if (strutil::starts_with(name, L"绿队 |")) {
		return std::make_pair(name.substr(5), nvgRGBA(144, 238, 144, 255));
	}
	else if (strutil::starts_with(name, L"黄队 |")) {
		return std::make_pair(name.substr(5), nvgRGBA(255, 255, 102, 255));
	}
	else if (strutil::starts_with(name, L"§")) {
		if (name.size() > 1 && colorMap.find(name[1]) != colorMap.end()) {
			return std::make_pair(name.substr(2), colorMap[name[1]]);
		}
	}
	return std::make_pair(name, nvgRGBA(255, 255, 255, 255));
}


void ESP::onRender(const EventRender2D& e) {
	ToggleCheck;
	if (Wrapper::Minecraft::getMinecraft().getWorld().isNULL())return;
	static auto& renderer = Renderer::get();
	auto vg = NanoVGHelper::Context;
	if (Younkoo::get().info.major == MajorVersion::MAJOR_189 or Younkoo::get().info.major == MajorVersion::MAJOR_112) {

		std::lock_guard<std::mutex> lock(vectorMutex);
		for (Data data : renderData)
		{
			auto &bv = data.boxVerticies;

			float left = FLT_MAX;
			float top = FLT_MAX;
			float right = FLT_MIN;
			float bottom = FLT_MIN;

			bool skip = false;
			for (Math::Vector3D &position : bv)
			{
				Math::Vector2D p;

				if (!Math::W2S::WorldToScreen(position, CommonData::get().modelView, CommonData::get().projection, renderer.renderContext.winSize.first, renderer.renderContext.winSize.second, p))
				{
					skip = true;
					break;
				}
				// This is a neat trick to get the top left and bottom right corners of all the box verticies quickly.
				left = fmin(p.x, left);
				top = fmin(p.y, top);
				right = fmax(p.x, right);
				bottom = fmax(p.y, bottom);
			}

			// This is for when the world to screen fails, we just want to ignore rendering the entire box completely.
			// The fade stuff will compensate for it randomly disappearing when you're too close.
			if (skip)
				continue;

			// The rest is just rendering the ESP with the customizable options, self explanitory.
			NanoVGHelper::drawRoundedOutlineRect(vg, left, top, right - left, bottom - top, 0.f, this->outlineWidth.get()->getValue() + 1.0f, NanoVGHelper::rgbaToColor(0, 0, 0, 255));
			NanoVGHelper::drawRoundedOutlineRect(vg, left, top, right - left, bottom - top, 0.f, this->outlineWidth.get()->getValue() , NanoVGHelper::rgbaToColor(255, 255, 255, 255));
			/*
			* ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(left - 3, top), ImVec2(left - 1, bottom), ImColor(FilledBoxColorValue->getValue()[0], FilledBoxColorValue->getValue()[1], FilledBoxColorValue->getValue()[2], FilledBoxOpacity * data.opacityFadeFactor));

			if (data.health <= 0)
				data.health = 0.00001f;

			float scaleFactor = data.health / data.maxHealth;
			float diff = bottom - top;

			ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(left - 3, bottom - (diff * scaleFactor)), ImVec2(left - 1, bottom), ImColor((int)(255 * (1.0 - scaleFactor)), (int)(255 * scaleFactor), 0, (int)(255 * data.opacityFadeFactor)));
			*/
			nvgBeginPath(vg);
			nvgRect(vg, left - 3, top, 2, bottom - top);
			nvgFillColor(vg, nvgRGBA(0, 0, 0, 0.15f * data.opacityFadeFactor));
			nvgFill(vg);

			if (data.health <= 0)
				data.health = 0.00001f;

			float scaleFactor = data.health / data.maxHealth;
			float diff = bottom - top;

			nvgBeginPath(vg);
			nvgRect(vg, left - 3, bottom - (diff * scaleFactor), 2, diff * scaleFactor);
			nvgFillColor(vg, nvgRGBA((int)(255 * (1.0 - scaleFactor)), (int)(255 * scaleFactor), 0, (int)(255 * data.opacityFadeFactor)));
			nvgFill(vg);
		}
		return;
	}

	int nextBufferIndex = (currentBufferIndex + 1) % 2;
	if (entitiesToRender[nextBufferIndex].empty()) return;
	currentBufferIndex = nextBufferIndex;
	for (const auto& entity : entitiesToRender[currentBufferIndex]) {
		auto entityName = wstr::toString(entity.name);

		int color = 0;
		if (teamBasedColorValue->getValue())
		{
			auto teamColor = parseName(entityName).second;
			color = NanoVGHelper::rgbaToColor(teamColor.r * 255, teamColor.g * 255, teamColor.b * 255, 255);
		}
		else {
			color = NanoVGHelper::rgbaToColor(this->RGB_R.get()->getValue(), this->RGB_G.get()->getValue(), this->RGB_B.get()->getValue(), 255);
		}
		if (HealthBar.get()) {
			float temp_health = entity.health;
			if (temp_health <= 0)
				temp_health = 0.00001f;
			//
			float scaleFactor = temp_health / entity.max_health;
			float diff = entity.bottom - entity.top;
			//blank backguard
			NanoVGHelper::drawOutlineRect(vg, entity.left - 6, entity.top, 1, entity.bottom - entity.top, 2.0f, NanoVGHelper::rgbaToColor(0, 0, 0, 100));
			//health bar outline
			NanoVGHelper::drawOutlineRect(vg, entity.left - 6, entity.top - ((diff * scaleFactor) - diff), 1, (diff * scaleFactor), 2.0f, NanoVGHelper::rgbaToColor(0, 0, 0, 255));
			//health bar
			NanoVGHelper::drawOutlineRect(vg, entity.left - 6, entity.top - ((diff * scaleFactor) - diff), 1, (diff * scaleFactor), 1.0f, NanoVGHelper::rgbaToColor(0, 255, 0, 255));
		}
		
		if (this->Newstyle.get()->getValue()) {
			NanoVGHelper::drawRoundedOutlineRect1(vg, entity.left, entity.top, entity.right - entity.left, entity.bottom - entity.top, 0.f, this->outlineWidth.get()->getValue() + 1.0f, NanoVGHelper::rgbaToColor(0, 0, 0, 255));
			NanoVGHelper::drawRoundedOutlineRect1(vg, entity.left, entity.top, entity.right - entity.left, entity.bottom - entity.top, 0.f, this->outlineWidth.get()->getValue(), color);
		} else {
			NanoVGHelper::drawRoundedOutlineRect(vg, entity.left, entity.top, entity.right - entity.left, entity.bottom - entity.top, 0.f, this->outlineWidth.get()->getValue() + 1.0f, NanoVGHelper::rgbaToColor(0, 0, 0, 255));
			NanoVGHelper::drawRoundedOutlineRect(vg, entity.left, entity.top, entity.right - entity.left, entity.bottom - entity.top, 0.f, this->outlineWidth.get()->getValue(), color);
		}
	}
}


void ESP::onRender3D(const EventRender3D& e) {
	ToggleCheck;
	if (NanoGui::available) return;

	const auto& renderContext = Renderer::get().renderContext;
	viewport = { 0, 0, renderContext.winSize.first, renderContext.winSize.second };

	auto mc = Wrapper::Minecraft::getMinecraft();
	if (!mc.getObject()) return;

	auto level = mc.getWorld();
	auto players = level.getPlayerList();
	auto& renderer = Renderer::get();

	std::vector<EntityData> newEntities;

	for (auto& player : players) {
		auto postion = player.getPosition(e.TICK_DELTA);
		/*RECT rect;
		GetClientRect(renderer.renderContext.HandleWindow, &rect);
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;*/

		auto renderPos = postion - e.CAMERA_POS;
		auto entityHeight = player.getHeight() + 0.15f;
		auto entityWidth = player.getWidth();

		using namespace Math;
		std::array<Vector3D, 10> posArray = {
			renderPos,
			renderPos - Vector3D{0, -entityHeight, 0}, // Over the head
			renderPos - Vector3D{entityWidth, 0, 0}, // In the middle to the left
			renderPos - Vector3D{-entityWidth, 0, 0}, // In the middle to the right
			renderPos - Vector3D{0, 0, entityWidth}, // In the middle to the back
			renderPos - Vector3D{0, 0, -entityWidth}, // In the middle to the front
			renderPos - Vector3D{entityWidth / 1.388888, 0, entityWidth}, // Middle left
			renderPos - Vector3D{-entityWidth / 1.388888, 0, -entityWidth}, // Middle right
			renderPos - Vector3D{-entityWidth / 1.388888, 0, entityWidth}, // Middle back
			renderPos - Vector3D{entityWidth / 1.388888, 0, -entityWidth} // Middle front
		};

		bool ok = true;
		float leftPoint = FLT_MAX;
		float topPoint = FLT_MAX;
		float rightPoint = FLT_MIN;
		float bottomPoint = FLT_MIN;

		for (const auto& pos : posArray) {
			auto result = W2S::world2Screen(structToArray(e.MODELVIEW_MATRIX), structToArray(e.PROJECTION_MATRIX), pos, viewport, 1);
			Vector2 point{ result[0], result[1] };

			if (result[2] > 0 && result[2] < 1) {
				leftPoint = std::min(point.x, leftPoint);
				topPoint = std::min(point.y, topPoint);
				rightPoint = std::max(point.x, rightPoint);
				bottomPoint = std::max(point.y, bottomPoint);
			}
			else {
				ok = false;
				break;
			}
		}

		if (ok) {
			auto result = W2S::world2Screen(structToArray(e.MODELVIEW_MATRIX), structToArray(e.PROJECTION_MATRIX), Vector3D(renderPos.x, renderPos.y + entityHeight + 0.3f, renderPos.z), viewport, 1);

			newEntities.push_back(EntityData{
				.name = player.getDisplayName(),
				.name_pos = Vector2(result[0], result[1]),
				.health = player.getHealth(),
				.max_health = player.getMaxHealth(),
				.top = topPoint,
				.bottom = bottomPoint,
				.left = leftPoint,
				.right = rightPoint
				});
		}
	}
	entitiesToRender[currentBufferIndex] = {};
	int nextBufferIndex = (currentBufferIndex + 1) % 2;
	entitiesToRender[nextBufferIndex] = std::move(newEntities);
	//currentBufferIndex = nextBufferIndex;
}