	#include "gui/components/components.hpp"
#include "fiber_pool.hpp"

namespace big
{
	bool components::button(const std::string_view text) {
		return ImGui::Button(text.data());
	}

	void components::button(const std::string_view text, std::function<void()> cb) {
		if (components::button(text)) {
			g_fiber_pool->queue_job(cb);
		}
	}

	void components::button(const std::string_view text, const std::string_view tooltip, std::function<void()> cb) {
		if (components::button(text)) {
			g_fiber_pool->queue_job(cb);
		}

		if (ImGui::IsItemHovered())
			ImGui::SetTooltip(tooltip.data());
	}
}