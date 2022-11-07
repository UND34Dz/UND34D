#pragma once

#include "common.hpp"

#include "services/players/player_service.hpp"

namespace big
{
	class looped {
	public:
		static void hud_transition_state();

		static void tunables_disable_phone();
		static void tunables_clean_player();
		static void tunables_ignoreplayer();
		static void tunables_mobileradio();
		static void tunables_disablehud();
		static void phone_anim();
		static void tunables_no_idle_kick();
		static void always_control();
		static void disable_help_text();

		static void player_never_wanted(const player_ptr &player);
		static void player_spectate();
		static void player_freezeplayer();
		static void player_freezeallplayers();
		static void player_shakecam();
		static void player_chase();

		static void self_free_cam_disable_control_action();
		static void self_free_cam();
		static void self_godmode();
		static void self_invisibility();
		static void self_noclip_disable_control_action();
		static void self_noclip();
		static void self_no_ragdoll();
		static void self_off_radar();
		static void self_police();
		static void self_super_run();
		static void self_flash_run();
		static void self_aimbot();
		static void self_SuperMan();
		static void self_force_field();
		static void ragdoll_mp();
		static void self_no_collision();
		static void self_unlimited_oxygen();
		static void self_no_water_collision();

		static void script_starter();
		static void session_local_time();
		static void session_slowmotion();
		static void session_jumpingcars();
		static void session_rainbowtraffic();
		static void fast_join();
		
		static void world_population_control();

		static void system_disable_model_spawn_bypass();
		static void system_self_globals();
		static void system_update_pointers();
		static void system_desync_kick_protection();

		static void anti_cheat();

		static void vehicle_auto_drive();
		static void vehicle_boost_behavior();
		static void vehicle_despawn_bypass();
		static void vehicle_drive_on_water();
		static void vehicle_fly();
		static void vehicle_god_mode();
		static void vehicle_horn_boost();
		static void vehicle_jump();
		static void vehicle_instant_brake();
		static void vehicle_is_targetable();
		static void vehicle_ls_customs();
		static void vehicle_rainbow_paint();
		static void vehicle_seatbelt();
		static void vehicle_speedo_meter();
		static void vehicle_remove_speed_limit();
		static void vehicle_turn_signals();
		static void vehicle_flares();
		static void vehicle_chaff();
		static void vehicle_keep_vehicle_repaired();
		static void vehicle_headlightmul();
		static void vehicle_uniweap();
		static void vehicle_no_water_collision();

		static void weapons_ammo_special_type();
		static void weapons_cage_gun();
		static void weapons_cartoon_gun();
		static void custom_gun_disable_control_action();
		static void weapons_delete_gun();
		static void weapons_force_crosshairs();
		static void weapons_gravity_gun();
		static void weapons_increased_damage();
		static void weapons_infinite_ammo();
		static void weapons_infinite_mag();
		static void weapons_no_recoil();
		static void weapons_no_spread();
		static void weapons_repair_gun();
		static void weapons_steal_vehicle_gun();
		static void weapons_vehicle_gun();
		static void weapons_pewpew_gun();
		static void weapons_remote_pewpew();

		static void hotkeys_input();
		static void hotkeys_teleport_waypoint();
		static void hotkeys_teleport_objective();
	};
}
