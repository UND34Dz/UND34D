#include "gui/components/components.hpp"

namespace big
{
	float components::resize_float(float val)
	{
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		float scale = (io.DisplaySize.x * io.DisplaySize.y) / (1920.f * 1080.f);

		if (scale > 1.0f)
			scale = 1.f;

		if (g->window.auto_resize)
			return val * scale;
		else
			return val;
	}
	ImVec2 components::resize_imvector(ImVec2 vector)
	{
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		float scale = (io.DisplaySize.x * io.DisplaySize.y) / (1920.f * 1080.f);

		if (scale > 1.0f)
			scale = 1.f;

		if (g->window.auto_resize)
			return ImVec2(vector.x * scale, vector.y * scale);
		else
			return vector;
	}
}