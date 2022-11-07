#include "views/view.hpp"
#include "fiber_pool.hpp"
#include "util/session.hpp"

namespace big
{
	void view::session()
	{
		static uint64_t rid = 0;
		ImGui::InputScalar("Input RID", ImGuiDataType_U64, &rid);
		components::button("Join RID", []
		{
			session::join_by_rockstar_id(rid);
		});

		components::sub_title("Session Switcher");
		if (ImGui::ListBoxHeader("###session_switch"))
		{
			for (const auto& session_type : sessions)
			{
				components::selectable(session_type.name, false, [&session_type]
					{
						session::join_type(session_type.id);
					});
			}
			ImGui::EndListBox();
		}

		components::sub_title("Settings");
		ImGui::Checkbox("Disable Stock Chat Filter", &g->session.disable_chat_filter);
		ImGui::Checkbox("Fast Join", &g->tunables.fast_join);

		ImGui::Separator();

		ImGui::Checkbox("Jumping Cars", &g->session.jumpingcars);
		ImGui::Checkbox("Rainbow Traffic", &g->session.rainbowtraffic);

		components::button("Kill Peds", [] {
			entity::KillNearbyPeds();
			});

		ImGui::SameLine();

		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.69f, 0.29f, 0.29f, 1.00f));
		if (*g_pointers->m_is_session_started)
		{
			components::button("Kick all", []
				{
					for (const auto& [_, player] : g_player_service->players())
					{
						gta_util::get_network_player_mgr()->RemovePlayer(player->get_net_game_player());

						LOG(G3LOG_DEBUG) << std::format("Sent desync to {}", player->get_name());

						script::get_current()->yield();
					}
				});
		}
		ImGui::PopStyleColor();
	}
}
