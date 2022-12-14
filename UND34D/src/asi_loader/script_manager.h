#pragma once

enum eGameVersion : int
{
	VER_1_0_335_2_STEAM,
	VER_1_0_335_2_NOSTEAM,

	VER_1_0_350_1_STEAM,
	VER_1_0_350_2_NOSTEAM,

	VER_1_0_372_2_STEAM,
	VER_1_0_372_2_NOSTEAM,

	VER_1_0_393_2_STEAM,
	VER_1_0_393_2_NOSTEAM,

	VER_1_0_393_4_STEAM,
	VER_1_0_393_4_NOSTEAM,

	VER_1_0_463_1_STEAM,
	VER_1_0_463_1_NOSTEAM,

	VER_1_0_505_2_STEAM,
	VER_1_0_505_2_NOSTEAM,

	VER_1_0_573_1_STEAM,
	VER_1_0_573_1_NOSTEAM,

	VER_1_0_617_1_STEAM,
	VER_1_0_617_1_NOSTEAM,

	VER_1_0_678_1_STEAM,
	VER_1_0_678_1_NOSTEAM,

	VER_1_0_757_2_STEAM,
	VER_1_0_757_2_NOSTEAM,

	VER_1_0_757_4_STEAM,
	VER_1_0_757_4_NOSTEAM,

	VER_1_0_791_2_STEAM,
	VER_1_0_791_2_NOSTEAM,

	VER_1_0_877_1_STEAM,
	VER_1_0_877_1_NOSTEAM,

	VER_1_0_944_2_STEAM,
	VER_1_0_944_2_NOSTEAM,

	VER_1_0_1011_1_STEAM,
	VER_1_0_1011_1_NOSTEAM,

	VER_1_0_1032_1_STEAM,
	VER_1_0_1032_1_NOSTEAM,

	VER_1_0_1103_2_STEAM,
	VER_1_0_1103_2_NOSTEAM,

	VER_1_0_1180_2_STEAM,
	VER_1_0_1180_2_NOSTEAM,

	VER_1_0_1290_1_STEAM,
	VER_1_0_1290_1_NOSTEAM,

	VER_1_0_1365_1_STEAM,
	VER_1_0_1365_1_NOSTEAM,

	VER_1_0_1493_0_STEAM,
	VER_1_0_1493_0_NOSTEAM,

	VER_1_0_1493_1_STEAM,
	VER_1_0_1493_1_NOSTEAM,

	VER_1_0_1604_0_STEAM,
	VER_1_0_1604_0_NOSTEAM,

	VER_1_0_1604_1_STEAM,
	VER_1_0_1604_1_NOSTEAM,

	VER_1_0_1737_0_STEAM,
	VER_1_0_1737_0_NOSTEAM,

	VER_1_0_1737_6_STEAM,
	VER_1_0_1737_6_NOSTEAM,

	VER_1_0_1868_0_STEAM,
	VER_1_0_1868_0_NOSTEAM,

	VER_1_0_1868_1_STEAM,
	VER_1_0_1868_1_NOSTEAM,
	VER_1_0_1868_4_EPIC,

	VER_1_0_2060_0_STEAM,
	VER_1_0_2060_0_NOSTEAM,

	VER_1_0_2060_1_STEAM,
	VER_1_0_2060_1_NOSTEAM,

	VER_1_0_2189_0_STEAM,
	VER_1_0_2189_0_NOSTEAM,

	VER_SIZE,
	VER_UNK = -1
};

namespace ScriptManager {

	void					WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
}