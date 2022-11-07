#pragma once
#include "natives.hpp"

namespace big::world
{
	inline void play_anim(const char* Dict, const char* ID)
	{
		STREAMING::REQUEST_ANIM_DICT(Dict);
		if (STREAMING::HAS_ANIM_DICT_LOADED(Dict))
		{
			g_notification_service->push_warning("Animation", "Playing Animation");
		}
		if (!STREAMING::HAS_ANIM_DICT_LOADED(Dict))
		{
			return;
		}
		TASK::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), Dict, ID, 4.0f, -4.0f, -1, 1, 1, 0, 0, 0);
	}

	inline void play_scenario(const char* Scene)
	{
		TASK::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), Scene, 0, true);
	}


	char const* animlistName[] = { "Sechs F", "Sechs M", "Private Dance", "Pole Dance", "Push Ups", "Sit Ups", "Celebrate", "Shocked", "Suicide Pistol", "Suicide Pill", "Showering" };

	char const* animlistDict[] = { "rcmpaparazzo_2", "rcmpaparazzo_2", "mini@strip_club@private_dance@part1", "mini@strip_club@pole_dance@pole_dance1", "amb@world_human_push_ups@male@base",
		"amb@world_human_sit_ups@male@base", "rcmfanatic1celebrate", "ragdoll@human", "mp_suicide", "mp_suicide", "mp_safehouseshower@male@" };

	char const* animlistID[] = { "shag_loop_poppy", "shag_loop_a", "priv_dance_p1", "pd_dance_01", "base", "base", "celebrate", "electrocute", "pistol", "pill", "male_shower_idle_b" };


	char const* scenelist[] = { "Coffee", "Smoke", "Binocular", "Freeway", "Slumped", "Standing", "Wash", "Park Attendant", "Cheering", "Clipboard", "Drill", "Cop Idle",
		"Drinking", "Drug Dealer", "Drug Dealer Hard", "Film SHocking", "Leaf Blower", "Gardener", "Golf Player", "Guard Patrol", "Guard Stand", "Guard Stand Army", "Hammering", "Hangout",
		"Hiker", "Hiker Standing", "Human Statue", "Janitor", "Jogging", "Jog Standing", "Leaning", "Maid Clean", "Flex", "Free Weights", "Musician", "Paparazzi", "Partying", "Picnic",
		"Prostitute High Class", "Prostitute Low Class", "Pushups", "Seat Ledge", "Seat Ledge Nom Nom", "Seat Steps", "Seat Wall", "Seat Wall Eating", "Security Torch", "Situps", "Smoking",
		"Smoking Pot", "Stand Fire", "Fishing", "Impatient", "Impatient Upright", "Stand Mobile", "Stand Mobile Upright", "Strip Watch Stand", "Stupor", "Sunbathe", "Sunbathe Back",
		"Tennis Player", "Tourist Map", "Tourist mobile", "Welding", "Window Shop", "Yoga", "Aim", "BBQ", "BIN", "Shopping Cart", "Chin Ups", "Parking Meter", "Seat Bar", "Seat bench",
		"Bench Press", "Strip Watch", "Medic Kneel", "Tend to Dead", "Time of Death", "Crowd Control", "Investigate" };

	char const* sceneID[] = { "WORLD_HUMAN_AA_COFFEE", "WORLD_HUMAN_AA_SMOKE", "WORLD_HUMAN_BINOCULARS", "WORLD_HUMAN_BUM_FREEWAY", "WORLD_HUMAN_BUM_SLUMPED", "WORLD_HUMAN_BUM_STANDING", "WORLD_HUMAN_BUM_WASH",
		"WORLD_HUMAN_CAR_PARK_ATTENDANT", "WORLD_HUMAN_CHEERING", "WORLD_HUMAN_CLIPBOARD", "WORLD_HUMAN_CONST_DRILL", "WORLD_HUMAN_COP_IDLES", "WORLD_HUMAN_DRINKING", "WORLD_HUMAN_DRUG_DEALER",
		"WORLD_HUMAN_DRUG_DEALER_HARD", "WORLD_HUMAN_MOBILE_FILM_SHOCKING", "WORLD_HUMAN_GARDENER_LEAF_BLOWER", "WORLD_HUMAN_GARDENER_PLANT", "WORLD_HUMAN_GOLF_PLAYER", "WORLD_HUMAN_GUARD_PATROL",
		"WORLD_HUMAN_GUARD_STAND", "WORLD_HUMAN_GUARD_STAND_ARMY", "WORLD_HUMAN_HAMMERING", "WORLD_HUMAN_HANG_OUT_STREET", "WORLD_HUMAN_HIKER", "WORLD_HUMAN_HIKER_STANDING", "WORLD_HUMAN_HUMAN_STATUE",
		"WORLD_HUMAN_JANITOR", "WORLD_HUMAN_JOG", "WORLD_HUMAN_JOG_STANDING", "WORLD_HUMAN_LEANING", "WORLD_HUMAN_MAID_CLEAN", "WORLD_HUMAN_MUSCLE_FLEX", "WORLD_HUMAN_MUSCLE_FREE_WEIGHTS", "WORLD_HUMAN_MUSICIAN",
		"WORLD_HUMAN_PAPARAZZI", "WORLD_HUMAN_PARTYING", "WORLD_HUMAN_PICNIC", "WORLD_HUMAN_PROSTITUTE_HIGH_CLASS", "WORLD_HUMAN_PROSTITUTE_LOW_CLASS", "WORLD_HUMAN_PUSH_UPS", "WORLD_HUMAN_SEAT_LEDGE",
		"WORLD_HUMAN_SEAT_LEDGE_EATING", "WORLD_HUMAN_SEAT_STEPS", "WORLD_HUMAN_SEAT_WALL", "WORLD_HUMAN_SEAT_WALL_EATING", "WORLD_HUMAN_SECURITY_SHINE_TORCH", "WORLD_HUMAN_SIT_UPS", "WORLD_HUMAN_SMOKING",
		"WORLD_HUMAN_SMOKING_POT", "WORLD_HUMAN_STAND_FIRE", "WORLD_HUMAN_STAND_FISHING", "WORLD_HUMAN_STAND_IMPATIENT", "WORLD_HUMAN_STAND_IMPATIENT_UPRIGHT", "WORLD_HUMAN_STAND_MOBILE",
		"WORLD_HUMAN_STAND_MOBILE_UPRIGHT", "WORLD_HUMAN_STRIP_WATCH_STAND", "WORLD_HUMAN_STUPOR", "WORLD_HUMAN_SUNBATHE", "WORLD_HUMAN_SUNBATHE_BACK", "WORLD_HUMAN_TENNIS_PLAYER", "WORLD_HUMAN_TOURIST_MAP",
		"WORLD_HUMAN_TOURIST_MOBILE", "WORLD_HUMAN_WELDING", "WORLD_HUMAN_WINDOW_SHOP_BROWSE", "WORLD_HUMAN_YOGA", "PROP_HUMAN_ATM", "PROP_HUMAN_BBQ", "PROP_HUMAN_BUM_BIN", "PROP_HUMAN_BUM_SHOPPING_CART",
		"PROP_HUMAN_MUSCLE_CHIN_UPS_ARMY", "PROP_HUMAN_PARKING_METER", "PROP_HUMAN_SEAT_BAR", "PROP_HUMAN_SEAT_BENCH", "PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS", "PROP_HUMAN_SEAT_STRIP_WATCH", "CODE_HUMAN_MEDIC_KNEEL",
		"CODE_HUMAN_MEDIC_TEND_TO_DEAD", "CODE_HUMAN_MEDIC_TIME_OF_DEATH", "CODE_HUMAN_POLICE_CROWD_CONTROL", "CODE_HUMAN_POLICE_INVESTIGATE" };


	char const* visionList[] = { "Camera View", "Stoned", "RedMist", "Cocaine", "Drug Gas", "Wobbly", "Drunk", "Bloom", "Contrast", "Nostalgic", "Hallucination", "Low Graphics", "Chop View", "AAAAAAAA" };

	char const* visionID[] = { "CAMERA_secuirity_FUZZ", "stoned", "REDMIST", "drug_flying_base", "DRUG_gas_huffin", "drug_wobbly", "Drunk", "Bloom", "PlayerSwitchPulse", "MP_Killstreak", "player_transition", "cinema_001", "CHOP", "BarryFadeOut" };

}