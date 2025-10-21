#pragma once
#include <optional>
#include <string>
struct PlayerInfo
{
	std::string NETEASE_USERID;
};


namespace JammingAPI {
	std::optional<PlayerInfo> QueryUserInfoFromName(const std::string& player_name);
	std::optional<PlayerInfo> QueryUserInfoFromUUID(const std::string& player_uuid);
	bool DoEat(const PlayerInfo& info);
	bool InitGameID();
}