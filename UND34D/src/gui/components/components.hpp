#pragma once
#include "imgui.h"
#include "misc/cpp/imgui_stdlib.h"

namespace big
{
	struct navigation_struct;
	enum class tabs;

	class components
	{
		static void custom_text(const std::string_view, ImFont*);
	public:
		static bool nav_button(const std::string_view);
		static bool button(const std::string_view);
		static void button(const std::string_view, std::string_view, std::function<void()>);
		static bool menu_item(const std::string_view);
		static void icon(const std::string_view);
		static void help_marker(const std::string_view);
		static void small_text(const std::string_view);
		static void sub_title(const std::string_view);
		static void title(const std::string_view);
		static void button(const std::string_view, std::function<void()>);
		static void menu_item(const std::string_view, std::function<void()>);
		static void nav_item(std::pair<tabs, navigation_struct>&, int);

		static void input_text_with_hint(const std::string_view label, const std::string_view hint, char* buf, size_t buf_size, ImGuiInputTextFlags flag = ImGuiInputTextFlags_None, std::function<void()> cb = nullptr);
		static void input_text_with_hint(const std::string_view label, const std::string_view hint, std::string* buf, ImGuiInputTextFlags flag = ImGuiInputTextFlags_None, std::function<void()> cb = nullptr);

		static bool selectable(const std::string_view, bool);
		static bool selectable(const std::string_view, bool, ImGuiSelectableFlags);
		static void selectable(const std::string_view, bool, std::function<void()>);
		static void selectable(const std::string_view, bool, ImGuiSelectableFlags, std::function<void()>);

		static float resize_float(float val);
		static ImVec2 resize_imvector(ImVec2 vector);
	};
}
