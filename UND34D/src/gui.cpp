#include "common.hpp"
#include "gta/player.hpp"
#include "gui.hpp"
#include "natives.hpp"
#include "script.hpp"

#include <imgui.h>
#include "widgets/imgui_hotkey.hpp"

#include "views/view.hpp"
#include "util/notify.hpp"
#include "fiber_pool.hpp"
#include "views/native/native.hpp"
#include "gui/ytd loader/ytd_loader.hpp"
#include <ShlObj_core.h>
namespace big
{
	void gui::dx_init()
	{
		static ImVec4 bgColor = ImVec4(0.09f, 0.094f, 0.129f, .9f);
		static ImVec4 primary = ImVec4(0.172f, 0.380f, 0.909f, 1.f);
		static ImVec4 secondary = ImVec4(0.443f, 0.654f, 0.819f, 1.f);
		static ImVec4 whiteBroken = ImVec4(0.792f, 0.784f, 0.827f, 1.f);

		auto& style = ImGui::GetStyle();
		style.WindowTitleAlign = { 0.5f, 0.5f };
		style.SelectableTextAlign = { 0.5f, 0.5f };
		style.WindowRounding = 0.f;
		style.WindowBorderSize = 1.f;
		style.ChildRounding = 1.f;
		style.PopupRounding = 0.f;
		style.AntiAliasedLines = true;
		style.AntiAliasedFill = true;
		style.CurveTessellationTol = 0.f;


		auto& colors = style.Colors;
		colors[ImGuiCol_Border] = ImGui::ColorConvertU32ToFloat4(ImColor(89, 66, 250, 204));
		colors[ImGuiCol_CheckMark] = ImGui::ColorConvertU32ToFloat4(ImColor(89, 34, 255, 255));
		colors[ImGuiCol_SliderGrab] = ImGui::ColorConvertU32ToFloat4(ImColor(89, 34, 255, 255));
		colors[ImGuiCol_Button] = ImGui::ColorConvertU32ToFloat4(ImColor(89, 34, 255, 255));
		colors[ImGuiCol_ChildBg] = ImColor(0, 0, 0, 255);

		
	}

	void gui::dx_on_tick()
	{
		static bool once_pos = true;
		if (once_pos)
		{
			ImGui::SetNextWindowPos(ImVec2(components::resize_float(217), 50));
			once_pos = false;
		}
		ImGui::SetNextWindowSize(components::resize_imvector(ImVec2(660.f, 600.f)));
		if (ImGui::Begin("UND34D", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar))
		{
			ImGui::SetScrollX(0.f);
			view::root();
		}
	}

	void gui::always_draw()
	{
		view::always();
	}

	void gui::script_on_tick()
	{
		TRY_CLAUSE
		{
			if (g_gui.m_opened)
			{
				for (uint8_t i = 0; i <= 6; i++)
					PAD::DISABLE_CONTROL_ACTION(2, i, true);
				PAD::DISABLE_CONTROL_ACTION(2, 106, true);
				PAD::DISABLE_CONTROL_ACTION(2, 329, true);
				PAD::DISABLE_CONTROL_ACTION(2, 330, true);

				PAD::DISABLE_CONTROL_ACTION(2, 14, true);
				PAD::DISABLE_CONTROL_ACTION(2, 15, true);
				PAD::DISABLE_CONTROL_ACTION(2, 16, true);
				PAD::DISABLE_CONTROL_ACTION(2, 17, true);
				PAD::DISABLE_CONTROL_ACTION(2, 24, true);
				PAD::DISABLE_CONTROL_ACTION(2, 69, true);
				PAD::DISABLE_CONTROL_ACTION(2, 70, true);
				PAD::DISABLE_CONTROL_ACTION(2, 84, true);
				PAD::DISABLE_CONTROL_ACTION(2, 85, true);
				PAD::DISABLE_CONTROL_ACTION(2, 99, true);
				PAD::DISABLE_CONTROL_ACTION(2, 92, true);
				PAD::DISABLE_CONTROL_ACTION(2, 100, true);
				PAD::DISABLE_CONTROL_ACTION(2, 114, true);
				PAD::DISABLE_CONTROL_ACTION(2, 115, true);
				PAD::DISABLE_CONTROL_ACTION(2, 121, true);
				PAD::DISABLE_CONTROL_ACTION(2, 142, true);
				PAD::DISABLE_CONTROL_ACTION(2, 241, true);
				PAD::DISABLE_CONTROL_ACTION(2, 261, true);
				PAD::DISABLE_CONTROL_ACTION(2, 257, true);
				PAD::DISABLE_CONTROL_ACTION(2, 262, true);
				PAD::DISABLE_CONTROL_ACTION(2, 331, true);
			}
		}
		EXCEPT_CLAUSE
	}
	Vector2 get_texture_scale(float size)
	{
		int x, y;
		GRAPHICS::GET_ACTUAL_SCREEN_RESOLUTION(&x, &y);
		return { (static_cast<float>(y) / static_cast<float>(x)) * size, size };
	}
	void gui::script_func()
	{
		/*std::string path = std::getenv("appdata");

		path += g_gui.texture;
		g_fiber_pool->queue_job([] {notify::above_map(std::format("Loaded UND34D.      "
			"Press {} to open", ImGui::key_names[g->settings.hotkeys.menu_toggle])); });
		ytd_file.load_ytd(path.c_str(), "tupoye.ytd");
		float size_txt = 0.15f;
		auto size_spinner = get_texture_scale(size_txt);*/
		while (true)
		{

			g_gui.script_on_tick();
			//if (g_gui.m_start_topoye)
			 //amount of seconds
			//g_native_gui.draw_texture(
			//	"tupoye",
			//	"tupoye_m",
			//	0.065f,
			//	0.65f, // good
			//	size_spinner.x,
			//	size_spinner.y,
			//	0.0f,
			//	255, 255, 255, 255);
				script::get_current()->yield();
		}			
	}
}