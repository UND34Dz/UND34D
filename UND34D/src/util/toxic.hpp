#pragma once
#include "gta/enums.hpp"
#include "enums/eExplosionTag.hpp"
#include "natives.hpp"
#include "script_global.hpp"
#include "system.hpp"
#include "entity.hpp"
#include "gta_util.hpp"
#include "services/players/player.hpp"
#include "gta/PickupRewards.h"
#include "util/teleport.hpp"
#include "util/vehicle.hpp"
#include "util/ped.hpp"
#include "services/players/player_service.hpp"

namespace big::toxic
{
	inline void blame_explode_coord(Player to_blame, Vector3 pos, eExplosionTag explosion_type, float damage, bool is_audible, bool is_invisible, float camera_shake)
	{
		system::patch_blame(true);
		FIRE::ADD_OWNED_EXPLOSION(
			PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(to_blame),
			pos.x, pos.y, pos.z,
			explosion_type,
			damage,
			is_audible,
			is_invisible,
			camera_shake
		);
		system::patch_blame(false);
	}

	inline void blame_explode_player(Player to_blame, Player target, eExplosionTag explosion_type, float damage, bool is_audible, bool is_invisible, float camera_shake)
	{
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), true);
		blame_explode_coord(to_blame, coords, explosion_type, damage, is_audible, is_invisible, camera_shake);
	}

	inline void bounty_player(Player target, int amount)
	{
		const size_t arg_count = 22;
		int64_t args[arg_count] = {
			static_cast<int64_t>(eRemoteEvent::Bounty),
			self::id,
			target,
			0, // set by player or NPC?
			amount,
			0, 1, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0,
			*script_global(1921039).at(9).as<int*>(),
			*script_global(1921039).at(10).as<int*>()
		};

		g_pointers->m_trigger_script_event(1, args, arg_count, -1);
	}

	inline void desync_kick(CNetGamePlayer *player)
	{
		gta_util::get_network_player_mgr()->RemovePlayer(player);
	}

	inline void disable_kill_trigger(bool toggle)
	{
		*script_global(2815059).at(6753).as<int*>() = toggle; // "TRI_WARP" 2nd nested if statement below this text in freemode.c
	}
	inline void clear_wanted_player(Player target)
	{
		constexpr size_t arg_count = 3;
		int64_t args[arg_count] = {
			static_cast<int64_t>(eRemoteEvent::ClearWantedLevel),
			self::id,
			*script_global(1892703).at(target, 599).at(510).as<int*>()
		};

		g_pointers->m_trigger_script_event(1, args, arg_count, 1 << target);
	}
		inline void destroyveh(Player pid)
	{
		Entity ent = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(pid);

		if (!PED::IS_PED_IN_ANY_VEHICLE(ent, true))
			g_notification_service->push_warning("Toxic", "Target player is not in a vehicle.");
		else {
			std::int64_t args[4] = { static_cast<int64_t>(eRemoteEvent::Destroyvehicle), pid, pid, pid };
			g_pointers->m_trigger_script_event(1, args, 4, 1 << pid);
			std::int64_t args2[10] = { static_cast<int64_t>(eRemoteEvent::VehicleKick), pid, pid, 0, 0, 0, 0, 1, pid, std::min(2147483647, MISC::GET_FRAME_COUNT()) };
			g_pointers->m_trigger_script_event(1, args2, 10, 1 << pid);
			g_notification_service->push("Toxic", "Destroyed Player Vehicle");
		}
	}
	namespace size
	{
		constexpr int globalplayer_bd = 453;
		constexpr int gpbd_fm_3 = 599;
		constexpr int gpbd_fm_1 = 888;
	}
	static inline script_global gpbd_fm_3(1892703);
	static inline script_global gsbd_fm_events(1920255);

	inline void kick(const Player player)
	{
		if (NETWORK::NETWORK_IS_HOST())
		{
			NETWORK::NETWORK_SESSION_KICK_PLAYER(player);
			g_notification_service->push("Toxic", "Kicked Player as Host");
			return;
		}
		//bad stuff here, look away kid

		g_notification_service->push("Toxic", "Kicked Player");
	}

	inline void bitching(const Player player)
	{
		int eclone[1000];
		int egcount = 0;
		while (egcount < 1)
		{
			Ped SelectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
			Hash stungun = RAGE_JOAAT("WEAPON_STUNGUN");
			Entity ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
			eclone[egcount] = PED::CLONE_PED(ped, true, false, true);
			ENTITY::SET_ENTITY_INVINCIBLE(eclone[egcount], false);
			ENTITY::SET_ENTITY_HEALTH(eclone[egcount], 1000, 0);
			PED::SET_PED_COMBAT_ABILITY(eclone[egcount], 100);
			WEAPON::GIVE_WEAPON_TO_PED(eclone[egcount], stungun, stungun, 9999, 9999);
			PED::SET_PED_CAN_SWITCH_WEAPON(eclone[egcount], true);
			TASK::TASK_COMBAT_PED(eclone[egcount], ped, 1, 1);
			PED::SET_PED_ALERTNESS(eclone[egcount], 1000);
			PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
			ENTITY::SET_PED_AS_NO_LONGER_NEEDED(&eclone[egcount]);
			egcount++;
			script::get_current()->yield(100ms);
		}
	}

	inline void bodyguard(const Player player)
	{
		int clone[1000];
		int gcount = 0;
		while (gcount < 1)
		{
			Ped SelectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
			Hash railgun = RAGE_JOAAT("WEAPON_RAILGUN");
			Entity ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
			//Ped enemy = TASK::TASK_COMBAT_HATED_TARGETS_AROUND_PED(SelectedPlayer, 20, 0);
			int my_group = PLAYER::GET_PLAYER_GROUP(SelectedPlayer);
			clone[gcount] = PED::CLONE_PED(ped, true, false, true);
			PED::SET_PED_AS_GROUP_LEADER(SelectedPlayer, my_group);
			PED::SET_PED_AS_GROUP_MEMBER(clone[gcount], my_group);
			PED::SET_PED_NEVER_LEAVES_GROUP(clone[gcount], 1);
			ENTITY::SET_ENTITY_INVINCIBLE(clone[gcount], true);
			ENTITY::SET_ENTITY_HEALTH(clone[gcount], 1000, 0);
			PED::SET_PED_COMBAT_ABILITY(clone[gcount], 100);
			WEAPON::GIVE_WEAPON_TO_PED(clone[gcount], railgun, railgun, 9999, 9999);
			PED::SET_PED_CAN_SWITCH_WEAPON(clone[gcount], true);
			TASK::TASK_COMBAT_HATED_TARGETS_AROUND_PED(player, 20, 0);
			PED::SET_GROUP_FORMATION(my_group, 1);
			PED::SET_PED_MAX_HEALTH(clone[gcount], 5000);
			PED::SET_PED_ALERTNESS(clone[gcount], 1000);
			PED::SET_PED_COMBAT_RANGE(clone[gcount], 1000);
			gcount++;
			script::get_current()->yield(100ms);
		}
	}
	inline void taze_player(const Player player)
	{
		const Ped target = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);

		constexpr auto max_attempts = 20;
		for (size_t attempts = 0; attempts < max_attempts && !ENTITY::IS_ENTITY_DEAD(target, false); attempts++)
		{
			const Vector3 destination = PED::GET_PED_BONE_COORDS(target, (int)PedBones::SKEL_ROOT, 0.0f, 0.0f, 0.0f);
			const Vector3 origin = PED::GET_PED_BONE_COORDS(target, (int)PedBones::SKEL_R_Hand, 0.0f, 0.0f, 0.2f);

			MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(origin.x, origin.y, origin.z, destination.x, destination.y, destination.z, 1, 0, RAGE_JOAAT("WEAPON_STUNGUN"), self::ped, false, true, 1);
		}
	}

	inline void kick_from_vehicle(const Player player)
	{
		const Ped target = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);

		TASK::CLEAR_PED_TASKS_IMMEDIATELY(target);
	}

	inline void flying_vehicle(const Player player)
	{
		Entity ent = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);

		if (!PED::IS_PED_IN_ANY_VEHICLE(ent, true))
			g_notification_service->push_warning("Toxic", "Target player is not in a vehicle.");
		else {
			ent = PED::GET_VEHICLE_PED_IS_IN(ent, false);

			if (entity::take_control_of(ent))
				ENTITY::APPLY_FORCE_TO_ENTITY(ent, 1, 0.f, 0.f, 50000.f, 0.f, 0.f, 0.f, 0, 0, 1, 1, 0, 1);
			else
				g_notification_service->push_warning("Toxic", "Failed to take control of player vehicle.");
		}
	}

	//
	// SechsMenu Code START
	//

	inline void send_to_cayo_perico(const Player target)
	{
		constexpr size_t arg_count = 3;
		int64_t args[arg_count] = {
			static_cast<int64_t>(eRemoteEvent::SendToCayoPerico),//SendToLocation
			self::id,
			target
		};

		g_pointers->m_trigger_script_event(1, args, arg_count, 1 << target);
	}

	inline static std::vector<int64_t> crash_hashes =
	{
		1480548969, 931221602, 668886109, -51486976, 1992522613, -1338917610, 1115266513, -1529596656, -2093023277, -1539131577, 495813132, -2085190907, 1488038476, 1674887089, 1007883955, 597430116,
		893081016, 886128956, 526822748, -637352381, -1991423686, -1013989798, -803535423, 1037001637, -397256754, 1111927333, -1388926377, -1908874529, -283041276, -768108950, -547323955
	};

	inline void tse_crash(int target) //thanks to cl1xa
	{
		//Wave I
		int64_t args1[] = { 526822748, -1, 500000, 849451549, -1, -1 };
		g_pointers->m_trigger_script_event(1, args1, sizeof(args1) / sizeof(args1[0]), 1 << target);

		int64_t args2[] = { -555356783, -1, 500000, 849451549, -1, -1 };
		g_pointers->m_trigger_script_event(1, args2, sizeof(args2) / sizeof(args2[0]), 1 << target);

		int64_t args3[] = { -637352381, -1, 500000, 849451549, -1, -1 };
		g_pointers->m_trigger_script_event(1, args3, sizeof(args3) / sizeof(args3[0]), 1 << target);

		int64_t args4[] = { -51486976, -1, 500000, 849451549, -1, -1 };
		g_pointers->m_trigger_script_event(1, args4, sizeof(args4) / sizeof(args4[0]), 1 << target);

		int64_t args5[] = { -1386010354, -1, 500000, 849451549, -1, -1 };
		g_pointers->m_trigger_script_event(1, args5, sizeof(args5) / sizeof(args5[0]), 1 << target);

		script::get_current()->yield();

		//Wave II
		int64_t args6[] = { 526822748, 23135423, 3, 827870001, 2022580431, -918761645, 1754244778, 827870001, 1754244778, 23135423, 827870001, 23135423 };
		g_pointers->m_trigger_script_event(1, args6, sizeof(args6) / sizeof(args6[0]), 1 << target);

		int64_t args7[] = { -555356783, 23135423, 3, 827870001, 2022580431, -918761645, 1754244778, 827870001, 1754244778, 23135423, 827870001, 23135423 };
		g_pointers->m_trigger_script_event(1, args7, sizeof(args7) / sizeof(args7[0]), 1 << target);

		int64_t args8[] = { -637352381, 23135423, 3, 827870001, 2022580431, -918761645, 1754244778, 827870001, 1754244778, 23135423, 827870001, 23135423 };
		g_pointers->m_trigger_script_event(1, args8, sizeof(args8) / sizeof(args8[0]), 1 << target);

		int64_t args9[] = { -51486976, 23135423, 3, 827870001, 2022580431, -918761645, 1754244778, 827870001, 1754244778, 23135423, 827870001, 23135423 };
		g_pointers->m_trigger_script_event(1, args9, sizeof(args9) / sizeof(args9[0]), 1 << target);

		int64_t args10[] = { -1386010354, 23135423, 3, 827870001, 2022580431, -918761645, 1754244778, 827870001, 1754244778, 23135423, 827870001, 23135423 };
		g_pointers->m_trigger_script_event(1, args10, sizeof(args10) / sizeof(args10[0]), 1 << target);

		script::get_current()->yield();

		//Wave III
		int64_t args11[] = { 526822748, target, 0, 30583, 0, 0, 0, -328966, 1132039228, 0 };
		g_pointers->m_trigger_script_event(1, args11, sizeof(args11) / sizeof(args11[0]), 1 << target);

		int64_t args12[] = { -555356783, target, 0, 30583, 0, 0, 0, -328966, 1132039228, 0 };
		g_pointers->m_trigger_script_event(1, args12, sizeof(args12) / sizeof(args12[0]), 1 << target);

		int64_t args13[] = { -637352381, target, 0, 30583, 0, 0, 0, -328966, 1132039228, 0 };
		g_pointers->m_trigger_script_event(1, args13, sizeof(args13) / sizeof(args13[0]), 1 << target);

		int64_t args14[] = { -51486976, target, 0, 30583, 0, 0, 0, -328966, 1132039228, 0 };
		g_pointers->m_trigger_script_event(1, args14, sizeof(args14) / sizeof(args14[0]), 1 << target);

		int64_t args15[] = { -1386010354, target, 0, 30583, 0, 0, 0, -328966, 1132039228, 0 };
		g_pointers->m_trigger_script_event(1, args15, sizeof(args15) / sizeof(args15[0]), 1 << target);

		script::get_current()->yield();

		//Elona Gay
		const int plyr = target;

		for (size_t i = 0; i < crash_hashes.size(); i++)
		{
			int64_t args1[] = { crash_hashes[i], -1, 500000, 849451549, -1, -1 };
			g_pointers->m_trigger_script_event(1, args1, sizeof(args1) / sizeof(args1[0]), 1 << plyr);

			script::get_current()->yield();

			int64_t args2[] = { crash_hashes[i], rand() % INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, INT64_MAX, rand() % INT64_MAX, rand() % INT64_MAX, };
			g_pointers->m_trigger_script_event(1, args2, sizeof(args2) / sizeof(args2[0]), 1 << plyr);

			script::get_current()->yield();
		}

		script::get_current()->yield();
	}

	//
	// SechsMenu Code END
	//


	inline void breakup_kick(player_ptr target) // From maybegreat48
	{
		rage::snMsgRemoveGamersFromSessionCmd cmd{};
		cmd.m_session_id = gta_util::get_network()->m_game_session_ptr->m_rline_session.m_session_id;
		cmd.m_num_peers = 1;
		cmd.m_peer_ids[0] = target->get_session_peer()->m_peer_data.m_peer_id_2;

		g_pointers->m_handle_remove_gamer_cmd(gta_util::get_network()->m_game_session_ptr, target->get_session_player(), &cmd);
		for (auto& [name, plyr] : g_player_service->players())
		{
			if (plyr->id() != target->id())
				g_pointers->m_send_remove_gamer_cmd(gta_util::get_network()->m_game_session_ptr->m_net_connection_mgr,
					g_pointers->m_get_connection_peer(gta_util::get_network()->m_game_session_ptr->m_net_connection_mgr, plyr->get_session_player()->m_player_data.m_peer_id_2),
					gta_util::get_network()->m_game_session_ptr->m_connection_identifier, &cmd, 0x1000000);
		}
	}

	inline void give_collectible(Player target, eCollectibleType col, int index = 0, bool uncomplete = false) // From maybegreat48
	{
		const size_t arg_count = 7;
		int64_t args[arg_count] = {
			(int64_t)eRemoteEvent::GiveCollectible,
			self::id,
			(int64_t)col, // iParam0
			index, // iParam1
			!uncomplete, // bParam2
			true,
			0  // bParam3
		};

		g_pointers->m_trigger_script_event(1, args, arg_count, 1 << target);
	}
	inline void Apartment(Player player)
	{
		std::int64_t args1[9] = { static_cast<int64_t>(eRemoteEvent::Teleport), player, player, 1, 0, 69, 1, 1, 1 };
		g_pointers->m_trigger_script_event(1, args1, 9, 1 << player);
	}

	inline void KICK_TO_SP(Player player)
	{
		std::int64_t argarr[4] = { static_cast<int64_t>(eRemoteEvent::KickToSP), player, 0, 0 };
		g_pointers->m_trigger_script_event(1, argarr, sizeof(argarr) / sizeof(argarr[0]), 1 << player);
	}

	inline void BurstTires(Player player)
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(player, false))
		{
			entity::take_control_of(PED::GET_VEHICLE_PED_IS_USING(player));
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(PED::GET_VEHICLE_PED_IS_USING(player), true);
			static int tireID = 0;
			for (tireID = 0; tireID < 8; tireID++)
			{
				VEHICLE::SET_VEHICLE_TYRE_BURST(PED::GET_VEHICLE_PED_IS_USING(player), tireID, true, 1000.0);
			}
		}
	}

	inline void LockDoors(Player player)
	{
		int lockStatus = VEHICLE::GET_VEHICLE_DOOR_LOCK_STATUS(player);
		if (PED::IS_PED_IN_ANY_VEHICLE(player, false))
		{
			entity::take_control_of(PED::GET_VEHICLE_PED_IS_USING(player));
			VEHICLE::SET_VEHICLE_DOORS_LOCKED(PED::GET_VEHICLE_PED_IS_USING(player), 4);
		}
	}

	inline void UnLockDoors(Player player)
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(player, false))
		{
			entity::take_control_of(PED::GET_VEHICLE_PED_IS_USING(player));
			VEHICLE::SET_VEHICLE_DOORS_LOCKED(PED::GET_VEHICLE_PED_IS_USING(player), 0);
		}
	}

	inline void ModelCrash(const Player player)
	{
		Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
		Vector3 playerCoords = ENTITY::GET_ENTITY_COORDS(ped, true);
		Vector3 selfCoords = ENTITY::GET_ENTITY_COORDS(self::ped, true);
		Vector3 location = Vector3(-4036, 8000, 1); //Away from Peds
		float Heading = ENTITY::GET_ENTITY_HEADING(player);
		Hash hash = VEHICLE_CYCLONE2; //Dont change unless its a invalid Car
		//Script starts here
		teleport::to_coords(location);
		script::get_current()->yield(3s);
		Vehicle veh = vehicle::spawn(hash, playerCoords, Heading, true);
		g_notification_service->push("Toxic", "Crash Model Spawned to Player");
		script::get_current()->yield(3s);
		entity::delete_entity(veh);
		g_notification_service->push("Toxic", "Deleted Invalid Model");
		script::get_current()->yield(5s);
		teleport::to_coords(selfCoords);
	}

	inline void ApplyForceToEntity(Entity e, float x, float y, float z)
	{
		if (e != self::id && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(e) == false)
		{
			entity::RequestNetworkControlOfEntity(e);
		}
		ENTITY::APPLY_FORCE_TO_ENTITY(e, 1, x, y, z, 0, 0, 0, 0, 1, 1, 1, 0, 1);
	}

	inline void CEO_BAN(Player player)
	{
		std::int64_t argarr[4] = { static_cast<int64_t>(eRemoteEvent::CeoBan), player, 1, 5 };
		g_pointers->m_trigger_script_event(1, argarr, sizeof(argarr) / sizeof(argarr[0]), 1 << player);
	}

	inline void CEO_KICK(Player player)
	{
		std::int64_t argarr[4] = { static_cast<int64_t>(eRemoteEvent::CeoKick), player, 1, 5 };
		g_pointers->m_trigger_script_event(1, argarr, sizeof(argarr) / sizeof(argarr[0]), 1 << player);
	}

	inline void FORCE_MISSION(Player player)
	{
		std::int64_t arguments_aray[3] = { static_cast<int64_t>(eRemoteEvent::ForceMission), player, 0 };
		g_pointers->m_trigger_script_event(1, arguments_aray, sizeof(arguments_aray) / sizeof(arguments_aray[0]), 1 << player);
	}

	inline void Spawn_G4E(Hash vehicle, float z)
	{
		Ped ply = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id());
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(ply, true) + Vector3(1, 1, z);
		float heading = ENTITY::GET_ENTITY_HEADING(PED::IS_PED_IN_ANY_VEHICLE(ply, false) ? PED::GET_VEHICLE_PED_IS_IN(ply, false) : ply);

		Vehicle veh = vehicle::spawn(vehicle, pos, heading, true);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, false);
		VEHICLE::CONTROL_LANDING_GEAR(veh, 3);

		static const Hash playerGroup = rage::joaat("PLAYER");
		static const Hash civGroup = rage::joaat("CIVMALE");
		static const Hash femCivGroup = rage::joaat("CIVFEMALE");

		Hash relationshipGroup;
		PED::ADD_RELATIONSHIP_GROUP("_HOSTILE_JESUS", &relationshipGroup);
		PED::SET_RELATIONSHIP_BETWEEN_GROUPS(5, relationshipGroup, playerGroup);
		PED::SET_RELATIONSHIP_BETWEEN_GROUPS(5, relationshipGroup, civGroup);
		PED::SET_RELATIONSHIP_BETWEEN_GROUPS(5, relationshipGroup, femCivGroup);

		Ped ped = ped::spawn_in_vehicle("u_m_m_jesus_01", veh, true);

		PED::SET_PED_RELATIONSHIP_GROUP_HASH(ped, relationshipGroup);
		PED::SET_PED_HEARING_RANGE(ped, 9999.f);
		PED::SET_PED_CONFIG_FLAG(ped, 281, true);


		TASK::TASK_PLANE_MISSION(ped, veh, 0, ply, 0, 0, 0, 6, 0.0, 0.0, 0.0, 2500.0, -1500.0, 0);
		TASK::TASK_VEHICLE_FOLLOW(ped, veh, ply, 540, 525117, 1);
		TASK::TASK_VEHICLE_SHOOT_AT_PED(ped, ply, 100);

		WEAPON::GIVE_WEAPON_TO_PED(ped, rage::joaat("WEAPON_RAILGUN"), 9999, true, true);
		TASK::TASK_COMBAT_PED(ped, ply, 0, 16);

		PED::SET_PED_FIRING_PATTERN(ped, 0xC6EE6B4C);
	}

	inline void EarRape()
	{
		Vector3 plyrCoords = ENTITY::GET_ENTITY_COORDS(g_player_service->get_selected()->id(), true);
		AUDIO::PLAY_SOUND_FROM_COORD(1, "BED", plyrCoords.x, plyrCoords.y, plyrCoords.z, "WASTEDSOUNDS", true, 0, false);
	}
	inline void turn_player_into_animal(Player target) // From maybegreat48
	{
		for (int i = 0; i < 30; i++)
		{
			toxic::give_collectible(target, eCollectibleType::Treat, 0, false);
			toxic::give_collectible(target, eCollectibleType::Treat, 0, true);
			g_pointers->m_give_pickup_rewards(1 << target, REWARD_HEALTH); // try to keep them alive
			g_pointers->m_give_pickup_rewards(1 << target, REWARD_ARMOUR);
			script::get_current()->yield(400ms);

			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
			Hash model = ENTITY::GET_ENTITY_MODEL(playerPed);

			if (model != RAGE_JOAAT("mp_m_freemode_01") && model != RAGE_JOAAT("mp_f_freemode_01"))
				return;

			if (ENTITY::IS_ENTITY_DEAD(playerPed, FALSE))
				script::get_current()->yield(7s);
		}

		g_notification_service->push_warning("Turn to Animal", "Failed to turn player into an animal");
	}
}
