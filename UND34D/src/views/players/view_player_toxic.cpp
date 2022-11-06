#include "views/view.hpp"
#include "gta_util.hpp"
#include "services/pickups/pickup_service.hpp"
#include "services/players/player_service.hpp"
#include "services/anti_cheat/anti_cheat_service.hpp"
#include "util/globals.hpp"
#include "util/misc.hpp"
#include "util/ped.hpp"
#include "util/vehicle.hpp"
#include "util/teleport.hpp"
#include "util/toxic.hpp"
#include "gta/joaat.hpp"
#include "core/enums.hpp"

namespace big
{
	void view::view_player_toxic()
	{
		if (!*g_pointers->m_is_session_started && g_player_service->get_selected()->is_valid()) return;

		std::string title = std::format("Player Toxic Options: {}", g_player_service->get_selected()->get_name());

		ImGui::Text(title.c_str());

		if (ImGui::TreeNode("Kicks and Crashes (Shit)")) {
			components::button("Desync", [] { toxic::desync_kick(g_player_service->get_selected()->get_net_game_player()); });
			ImGui::SameLine(); components::help_marker("Removes this player from your player manager.\nWill kick them if you are a host.\nOtherwise will just remove them localy.");
			ImGui::SameLine();

			if (gta_util::get_network()->m_game_session.is_host())
			{
				components::button("Host Kick", [] {
					NETWORK::NETWORK_SESSION_KICK_PLAYER(g_player_service->get_selected()->id());
					});
				ImGui::SameLine(); components::help_marker("Removes this player hosts player manager and adds them to session blacklist. \nBlacklist can be bypassed by RID spoofing. \nBlockable by breakup kicking host instantly.");
				ImGui::SameLine();
			}

			components::button("Breakup Kick", [] {
				toxic::breakup_kick(g_player_service->get_selected());
				});
			ImGui::SameLine(); components::help_marker("Removes this player from everyones player manager. \nCan be detected by anyone in session. \nUnblockable.");
			ImGui::SameLine();

			components::button("Ped Crash", [] {
				Ped ped = ped::spawn(ePedType::PED_TYPE_PROSTITUTE, rage::joaat("slod_human"), 0, ENTITY::GET_ENTITY_COORDS(g_player_service->get_selected()->id(), false), 0);
				script::get_current()->yield(3s);
				entity::delete_entity_notp(ped);
				});
			ImGui::SameLine(); components::help_marker("Spawns 'slod_human' ped near player wich crashes them. \nBlocked by most internal menus.");
			ImGui::SameLine();

			components::button("Vehicle Crash", [] {
				Vehicle veh = vehicle::spawn(rage::joaat("arbitergt"), ENTITY::GET_ENTITY_COORDS(g_player_service->get_selected()->id(), false), 0);
				script::get_current()->yield(3s);
				entity::delete_entity_notp(veh);
				});
			ImGui::SameLine(); components::help_marker("Spawns next_gen vehicle: 'arbitergt' near player wich crashes them. \nBlocked by most internal menus.");
			ImGui::SameLine();

			components::button("TSE Crash", [] {
				toxic::tse_crash(g_player_service->get_selected()->id());
				});
			ImGui::SameLine(); components::help_marker("Sends crash script events to the player. \nBlocked by most internal menus.");
			ImGui::TreePop();
		}


		if (ImGui::TreeNode("Ped")) {
			components::button("Clear Tasks", [] {
				TASK::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id()));
				});
			ImGui::SameLine(); components::help_marker("Stops any task player ped is doing. \nBlacked by most internal menus.");
			ImGui::SameLine();

			components::button("Ragdoll", [] {
				TASK::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id()));
				auto pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id()), true);
				FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 13, 1, false, true, 0, false);
				});
			ImGui::SameLine(); components::help_marker("Spawns an invisible fire hydrant below player. \nBlacked by using 'no ragdoll' or 'godmode'.");

			components::button("Turn Into Animal", [] {
				toxic::turn_player_into_animal(g_player_service->get_selected()->id());
				});
			ImGui::SameLine(); components::help_marker("Gives player a lot of jack o lanterns and eventually turns them into animal. \nCan be blocked.");

			components::button("Send to Cayo Perico", [] {
				toxic::send_to_cayo_perico(g_player_service->get_selected()->id());
				});

			ImGui::TreePop();
		}

		if (ImGui::TreeNode("Vehicle")) {

			components::button("Full Acceleration", [] {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id()), false);
				if (entity::take_control_of(veh))
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, VEHICLE::GET_VEHICLE_MODEL_ESTIMATED_MAX_SPEED(ENTITY::GET_ENTITY_MODEL(veh)) * 2);
				});
			ImGui::SameLine(); components::help_marker("Accelerates players vehicle to max speed. \nRequires entity control. \nBlacked by most internal menus.");
			ImGui::SameLine();

			components::button("Launch Vehicle Up", [] {
				toxic::flying_vehicle(g_player_service->get_selected()->id());
				});
			ImGui::SameLine(); components::help_marker("Launches players vehicle up. \nRequires entity control. \nBlacked by most internal menus.");

			components::button("Repair Vehicle", [] {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(g_player_service->get_selected()->id(), false);
				vehicle::repair(veh);
				});
			ImGui::SameLine(); components::help_marker("Repairs players vehicle. \nRequires entity control. \nBlacked by most internal menus.");
			ImGui::TreePop();
		}

		if (ImGui::TreeNode("Spawns")) {
			components::button("Spawn Griefer Jesus", [] {
				Ped player_ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id());
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(player_ped, true) + Vector3(0, 0, 10);
				ped::spawn_griefer_jesus(pos, player_ped);
				});
			ImGui::SameLine(); components::help_marker("Spawns 'Griefer Jesus' just like in ChaosMod.");
			ImGui::SameLine();

			components::button("Spawn Extreme Griefer Jesus", [] {
				Ped player_ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id());
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(player_ped, true) + Vector3(0, 0, 10);

				ped::spawn_extrime_griefer_jesus(pos, player_ped);
				});
			ImGui::SameLine(); components::help_marker("Spawns 'Extreme Griefer Jesus' just like in ChaosMod.");

			components::button("Spawn Griefer Lazer", [] {
				Ped player_ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id());
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(player_ped, true) + Vector3(0, 0, 500);
				Hash jet_hash RAGE_JOAAT("lazer");
				ped::spawn_griefer_jet(pos, player_ped, jet_hash);
				});
			ImGui::SameLine(); components::help_marker("Spawns a lazer with Griefer Jesus in it.");

			ImGui::TreePop();
		}
		if (!*g_pointers->m_is_session_started && g_player_service->get_selected()->is_valid()) return;

		ImGui::Text(title.c_str());

		components::button("Teleport", [] {
			teleport::to_player(g_player_service->get_selected()->id());
			});
		ImGui::SameLine(); components::help_marker("Teleports you to player.");
		ImGui::SameLine();

		components::button("Bring", [] {
			teleport::bring_player(g_player_service->get_selected()->id());
			});
		ImGui::SameLine(); components::help_marker("Teleports players vehicle to you. \nBlocked by most internal menus.");

		components::button("Godmode kill", [] {
			teleport::teleport_player(g_player_service->get_selected()->id(), Vector3(8110, 20, 0));
			script::get_current()->yield(1s);
			TASK::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id()));
			entity::delete_entity_notp(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id()), false));
			});
		ImGui::SameLine(); components::help_marker("Teleports players vehicle into the ocean. \nBlocked by most internal menus.");

		ImGui::SameLine();

		components::button("Teleport into Vehicle", [] {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id()), false);

			teleport::into_vehicle(veh);
			});
		if (!*g_pointers->m_is_session_started && g_player_service->get_selected()->is_valid()) return;

		ImGui::Text(title.c_str());

		components::button("Steal Outfit", [] {
			ped::steal_outfit(
				PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id())
			);
			});
		ImGui::SameLine(); components::help_marker("Will crash you after death.");
		ImGui::SameLine();

		components::button("Steal Identity", [] {
			ped::steal_identity(
				PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id())
			);
			});
		ImGui::SameLine(); components::help_marker("Will crash you after death.");

		components::button("Clear Wanted Level", [] {
			globals::clear_wanted_player(g_player_service->get_selected()->id());
			});

		ImGui::SameLine();

		ImGui::Checkbox("Never Wanted", &g_player_service->get_selected()->never_wanted);

		components::button("Give Health", [] {
			g_pickup_service->give_player_health(g_player_service->get_selected()->id());
			});

		ImGui::SameLine();

		components::button("Give Armour", [] {
			g_pickup_service->give_player_armour(g_player_service->get_selected()->id());
			});

		components::button("Give Ammo", [] {
			g_pickup_service->give_player_ammo(g_player_service->get_selected()->id());
			});

		ImGui::SameLine();

		components::button("Give All Weapons", [] {
			g_pickup_service->give_player_weapons(g_player_service->get_selected()->id());
			});

		std::string weapon_name;
		components::input_text_with_hint("###weapon_name", "Weapon Name. EG: weapon_unarmed", &weapon_name);

		components::button("Give Selected Weapon", [weapon_name] {
			Hash weaponHash = rage::joaat(weapon_name);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(g_player_service->get_selected()->id(), weaponHash, 9999, false);
			});

		ImGui::SameLine();

		components::button("Remove Selected Weapon", [weapon_name] {
			Hash weaponHash = rage::joaat(weapon_name);
			WEAPON::REMOVE_WEAPON_FROM_PED(g_player_service->get_selected()->id(), weaponHash);
			});
		}

}