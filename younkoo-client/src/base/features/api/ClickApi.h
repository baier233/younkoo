#pragma once

namespace ClickApi {
	enum class ClickType
	{
		DOWN,
		UP,
		BOTH
	};

	enum class MouseType
	{
		LEFT,
		RIGHT
	};
	void Init();
	void GenricClick(MouseType mouse, ClickType click);
	void GenricMCClick(MouseType mouse, ClickType click);
	inline int keyAttack = 0;
	inline int keyUse = 1;
}