#pragma once

namespace big
{
	enum class eBoostBehaviors
	{
		DEFAULT,
		INSTANT_REFIL,
		INFINITE_BOOST
	};

	enum class CustomWeapon
	{
		NONE,
		CAGE_GUN,
		DELETE_GUN,
		GRAVITY_GUN,
		STEAL_VEHICLE_GUN,
		REPAIR_GUN,
		VEHICLE_GUN,
		CARTOON_GUN,
		PEWPEW_GUN
	};

	enum class ContextEntityType : uint8_t
	{
		NONE = 0,
		PED = 1 << 0,
		PLAYER = 1 << 1,
		VEHICLE = 1 << 2,
		OBJECT = 1 << 3,
		SHARED = 1 << 4
	};

	enum class eEntityType
	{
		UNK_0,
		UNK_1,
		UNK_2,
		UNK_3,
		UNK_4,
		VEHICLE,
		PED,
	};

	enum class eTransitionState
	{
		TRANSITION_STATE_EMPTY,
		TRANSITION_STATE_SP_SWOOP_UP,
		TRANSITION_STATE_MP_SWOOP_UP,
		TRANSITION_STATE_CREATOR_SWOOP_UP,
		TRANSITION_STATE_PRE_HUD_CHECKS,
		TRANSITION_STATE_WAIT_HUD_EXIT,
		TRANSITION_STATE_WAIT_FOR_SUMMON,
		TRANSITION_STATE_SP_SWOOP_DOWN,
		TRANSITION_STATE_MP_SWOOP_DOWN,
		TRANSITION_STATE_CANCEL_JOINING,
		TRANSITION_STATE_RETRY_LOADING,
		TRANSITION_STATE_RETRY_LOADING_SLOT_1,
		TRANSITION_STATE_RETRY_LOADING_SLOT_2,
		TRANSITION_STATE_RETRY_LOADING_SLOT_3,
		TRANSITION_STATE_RETRY_LOADING_SLOT_4,
		TRANSITION_STATE_WAIT_ON_INVITE,
		TRANSITION_STATE_PREJOINING_FM_SESSION_CHECKS,
		TRANSITION_STATE_LOOK_FOR_FRESH_JOIN_FM,
		TRANSITION_STATE_LOOK_TO_JOIN_ANOTHER_SESSION_FM,
		TRANSITION_STATE_CONFIRM_FM_SESSION_JOINING,
		TRANSITION_STATE_WAIT_JOIN_FM_SESSION,
		TRANSITION_STATE_CREATION_ENTER_SESSION,
		TRANSITION_STATE_PRE_FM_LAUNCH_SCRIPT,
		TRANSITION_STATE_FM_TEAMFULL_CHECK,
		TRANSITION_STATE_START_FM_LAUNCH_SCRIPT,
		TRANSITION_STATE_FM_TRANSITION_CREATE_PLAYER,
		TRANSITION_STATE_IS_FM_AND_TRANSITION_READY,
		TRANSITION_STATE_FM_SWOOP_DOWN,
		TRANSITION_STATE_POST_BINK_VIDEO_WARP,
		TRANSITION_STATE_FM_FINAL_SETUP_PLAYER,
		TRANSITION_STATE_MOVE_FM_TO_RUNNING_STATE,
		TRANSITION_STATE_FM_HOW_TO_TERMINATE,
		TRANSITION_STATE_START_CREATOR_PRE_LAUNCH_SCRIPT_CHECK,
		TRANSITION_STATE_START_CREATOR_LAUNCH_SCRIPT,
		TRANSITION_STATE_CREATOR_TRANSITION_CREATE_PLAYER,
		TRANSITION_STATE_IS_CREATOR_AND_TRANSITION_READY,
		TRANSITION_STATE_CREATOR_SWOOP_DOWN,
		TRANSITION_STATE_CREATOR_FINAL_SETUP_PLAYER,
		TRANSITION_STATE_MOVE_CREATOR_TO_RUNNING_STATE,
		TRANSITION_STATE_PREJOINING_TESTBED_SESSION_CHECKS,
		TRANSITION_STATE_LOOK_FOR_FRESH_JOIN_TESTBED,
		TRANSITION_STATE_LOOK_FOR_FRESH_HOST_TESTBED,
		TRANSITION_STATE_LOOK_TO_JOIN_ANOTHER_SESSION_TESTBED,
		TRANSITION_STATE_LOOK_TO_HOST_SESSION_TESTBED,
		TRANSITION_STATE_CONFIRM_TESTBED_SESSION_JOINING,
		TRANSITION_STATE_WAIT_JOIN_TESTBED_SESSION,
		TRANSITION_STATE_START_TESTBED_LAUNCH_SCRIPT,
		TRANSITION_STATE_TESTBED_TRANSITION_CREATE_PLAYER,
		TRANSITION_STATE_IS_TESTBED_AND_TRANSITION_READY,
		TRANSITION_STATE_TESTBED_SWOOP_DOWN,
		TRANSITION_STATE_TESTBED_FINAL_SETUP_PLAYER,
		TRANSITION_STATE_MOVE_TESTBED_TO_RUNNING_STATE,
		TRANSITION_STATE_TESTBED_HOW_TO_TERMINATE,
		TRANSITION_STATE_QUIT_CURRENT_SESSION_PROMPT,
		TRANSITION_STATE_WAIT_FOR_TRANSITION_SESSION_TO_SETUP,
		TRANSITION_STATE_TERMINATE_SP,
		TRANSITION_STATE_WAIT_TERMINATE_SP,
		TRANSITION_STATE_KICK_TERMINATE_SESSION,
		TRANSITION_STATE_TERMINATE_SESSION,
		TRANSITION_STATE_WAIT_TERMINATE_SESSION,
		TRANSITION_STATE_TERMINATE_SESSION_AND_HOLD,
		TRANSITION_STATE_TERMINATE_SESSION_AND_MOVE_INTO_HOLDING_STATE,
		TRANSITION_STATE_TEAM_SWAPPING_CHECKS,
		TRANSITION_STATE_RETURN_TO_SINGLEPLAYER,
		TRANSITION_STATE_WAIT_FOR_SINGLEPLAYER_TO_START,
		TRANSITION_STATE_WAITING_FOR_EXTERNAL_TERMINATION_CALL,
		TRANSITION_STATE_TERMINATE_MAINTRANSITION,
		TRANSITION_STATE_WAIT_FOR_DIRTY_LOAD_CONFIRM,
		TRANSITION_STATE_DLC_INTRO_BINK
	};

	enum eVehicleFlags
	{
		TRIGGER_SPAWN_TOGGLE = 1 << 0,
		DESTROYED = 1 << 1,
		HAS_INSURANCE = 1 << 2,
		UNK0 = 1 << 3,
		IMPOUNDED = 1 << 6,
		UNK1 = 1 << 10,
		SPAWN_AT_MORS_MUTUAL = 1 << 11,
		UNK2 = 1 << 16
	};

    enum class ePedTask
    {
        TASK_NONE,
        TASK_FOOT = 1 << 4,
        TASK_UNK = 1 << 5,
        TASK_DRIVING = 1 << 6
    };
	
	enum class eRemoteEvent
	{
		Bounty = 1294995624, // (137, "FM_TXT_BNTY0", iVar1, PLAYER::GET_PLAYER_NAME(Var2.f_1), "", 5000, Var2.f_6);
		CeoBan = 1240068495, // mpply_vipgameplaydisabledtimer
		CeoKick = -1425016400, // BGDISMISSED
		CeoMoney = 547083265, // Goon_Paid_Large
		ClearWantedLevel = 1449852136,
		ForceMission = -283041276, // ), Var0.f_2, 1))
		ForceMission2 = -1908874529,
		GtaBanner = 145637109, // NETWORK::NETWORK_IS_SCRIPT_ACTIVE("BUSINESS_BATTLES", -1, true, 0) second one
		NetworkBail = 1674887089, // NETWORK::NETWORK_BAIL(16, 0, 0); xref func
		PersonalVehicleDestroyed = -1838276770, // PLYVEH_INS_DES1
		RemoteOffradar = -1973627888, // NETWORK::GET_TIME_DIFFERENCE(NETWORK::GET_NETWORK_TIME(), Var0.f_2)
		SendToCutscene = 2131601101, // (bVar3, bVar4, 125f, 1)
		SendToCayoPerico = 1361475530, // CELL_HI_INV
		SendToLocation = 1214823473, // &Var222, 11);
		SHKick = 1037001637,
		SoundSpam = 1111927333, // CELL_APTINVYACHT
		Spectate = -2131157870, // SPEC_TCK1
		Teleport = -1390976345, // Mission_Pass_Notify
		TeleportToWarehouse = 2130458390, // CAM::FORCE_CINEMATIC_RENDERING_THIS_UPDATE(true) xref counter
		TransactionError = -768108950, // NETWORK_RECEIVE_PLAYER_JOBSHARE_CASH
		VehicleKick = -714268990, // PIM_RFMOC
		Kick = 1674887089,
		GiveCollectible = -1178972880, // DLC_SUM20_HIDDEN_COLLECTIBLES xref
		ChangeMCRole = 656530441, // _PLAYSTATS_CHANGE_MC_ROLE
		DisableRecording = 867047895, // GET_FINAL_RENDERED_CAM_COORD
		MCTeleport = -555356783, // NETWORK::NETWORK_HASH_FROM_PLAYER_HANDLE(PLAYER::PLAYER_ID()) == (first one)
		KickToSP = 2071375245, 
		StartActivity = 1368055548, // (Var0.f_2, -1); first match

		Crash = 526822748, // SET_NO_LOADING_SCREEN, xref it
		Crash2 = 1348481963,
		Destroyvehicle = -2126830022,
		DisownVehicle = -306558546,
		BlockPassive = 65268844,

		TSECommand = -1388926377, // CnCTG_IN_BF
		TSECommandRotateCam = -1762807505, // != 29) && f

		Notification = -1529596656,
		NotificationMoneyBanked = -849958015, // TICK_TC_BANK
		NotificationMoneyRemoved = -290070531, // TICK_TC_REMO
		NotificationMoneyStolen = -1640162684, // TICK_TC_STOL
	};

	enum class eActivityType
	{
		HeistPrep = 233,
		Gunrunning = 180,
		Sightseer = 142,
		HeadHunter = 166,
		BuySpecialCargo = 167,
		SellSpecialCargo = 168,
		DefendSpecialCargo = 169,
		StealVehicle = 178,
		ExportVehicle = 188,
		Gunrunning2 = 225,
		GunrunningSell = 226,
		GunrunningDefend = 227,
		BikerSell = 190,
		BikerDefend = 191,
		BusinessResupply = 192,
		Survival = 3,
		Darts = 14,
		ArmWresling = 15,
		GangAttack = 6,
		PilotSchool = 122,
		Golf = 11,
		ShootingRange = 13,
		Tennis = 12,
		BaseJump = 8,
		Deathmatch = 1,
		ImpromptuDeathmatch = 5,
		Mission = 0,
		Race = 2,
		ExecutiveDeathmatch = 148,
		MarkedForDeath = 151,
		PiracyPrevention = 152,
		MostWanted = 153,
		AssetRecovery = 157,
		HostileTakeover = 159,
		Point2Point = 162,
		AmphibiousAssault = 216,
		Velocity = 219,
		GunsForHire = 185,
		ByThePound = 182,
		RippingItUp = 194,
		RaceToPoint = 189,
		HitAndRide = 193,
		CriminalMischief = 205,
		WeaponOfChoice = 186,
		FragileGoods = 207,
		Torched = 208,
		Outrider = 209,
		WheelieRider = 210,
		POW = 183,
		ExecutiveSearch = 199,
		StandYourGround = 201,
		AutoBuyout = 163,
		DueDiligence = 160,
		MarketManipulation = 154,
		CourierService = 155,
	};

	enum class eSessionType
	{
		JOIN_PUBLIC,
		NEW_PUBLIC,
		CLOSED_CREW,
		CREW,
		CLOSED_FRIENDS = 6,
		FIND_FRIEND = 9,
		SOLO,
		INVITE_ONLY,
		JOIN_CREW,
		SC_TV,
		LEAVE_ONLINE = -1
	};

	enum class SpeedUnit
	{
		KMPH,
		MIPH,
		MPS
	};

	enum class RainbowPaintType
	{
		Off,
		Fade,
		Spasm
	};

	enum class AutoDriveDestination
	{
		STOPPED,
		OBJECTITVE,
		WAYPOINT,
		WANDER,
		EMERGENCY_STOP
	};

	enum class AutoDriveStyle
	{
		LAW_ABIDING,
		THE_ROAD_IS_YOURS
	};

	enum class eEntityProofs : uint32_t
	{
		BULLET     = 1 << 4,
		FIRE       = 1 << 5,
		COLLISION  = 1 << 6,
		MELEE      = 1 << 7,
		GOD        = 1 << 8,
		EXPLOSION  = 1 << 11,
		STEAM      = 1 << 15,
		DROWN      = 1 << 16,
		WATER      = 1 << 24,
	};
	enum ePedType : uint32_t
	{
		PED_TYPE_PLAYER_0,
		PED_TYPE_PLAYER_1,
		PED_TYPE_NETWORK_PLAYER,
		PED_TYPE_PLAYER_2,
		PED_TYPE_CIVMALE,
		PED_TYPE_CIVFEMALE,
		PED_TYPE_COP,
		PED_TYPE_GANG_ALBANIAN,
		PED_TYPE_GANG_BIKER_1,
		PED_TYPE_GANG_BIKER_2,
		PED_TYPE_GANG_ITALIAN,
		PED_TYPE_GANG_RUSSIAN,
		PED_TYPE_GANG_RUSSIAN_2,
		PED_TYPE_GANG_IRISH,
		PED_TYPE_GANG_JAMAICAN,
		PED_TYPE_GANG_AFRICAN_AMERICAN,
		PED_TYPE_GANG_KOREAN,
		PED_TYPE_GANG_CHINESE_JAPANESE,
		PED_TYPE_GANG_PUERTO_RICAN,
		PED_TYPE_DEALER,
		PED_TYPE_MEDIC,
		PED_TYPE_FIREMAN,
		PED_TYPE_CRIMINAL,
		PED_TYPE_BUM,
		PED_TYPE_PROSTITUTE,
		PED_TYPE_SPECIAL,
		PED_TYPE_MISSION,
		PED_TYPE_SWAT,
		PED_TYPE_ANIMAL,
		PED_TYPE_ARMY
	};

	enum ePedConfigFlags
	{
		_CPED_CONFIG_FLAG_0x67D1A445 = 0,
		_CPED_CONFIG_FLAG_0xC63DE95E = 1,
		CPED_CONFIG_FLAG_NoCriticalHits = 2,
		CPED_CONFIG_FLAG_DrownsInWater = 3,
		CPED_CONFIG_FLAG_DisableReticuleFixedLockon = 4,
		_CPED_CONFIG_FLAG_0x37D196F4 = 5,
		_CPED_CONFIG_FLAG_0xE2462399 = 6,
		CPED_CONFIG_FLAG_UpperBodyDamageAnimsOnly = 7,
		_CPED_CONFIG_FLAG_0xEDDEB838 = 8,
		_CPED_CONFIG_FLAG_0xB398B6FD = 9,
		_CPED_CONFIG_FLAG_0xF6664E68 = 10,
		_CPED_CONFIG_FLAG_0xA05E7CA3 = 11,
		_CPED_CONFIG_FLAG_0xCE394045 = 12,
		CPED_CONFIG_FLAG_NeverLeavesGroup = 13,
		_CPED_CONFIG_FLAG_0xCD8D1411 = 14,
		_CPED_CONFIG_FLAG_0xB031F1A9 = 15,
		_CPED_CONFIG_FLAG_0xFE65BEE3 = 16,
		CPED_CONFIG_FLAG_BlockNonTemporaryEvents = 17,
		_CPED_CONFIG_FLAG_0x380165BD = 18,
		_CPED_CONFIG_FLAG_0x07C045C7 = 19,
		_CPED_CONFIG_FLAG_0x583B5E2D = 20,
		_CPED_CONFIG_FLAG_0x475EDA58 = 21,
		_CPED_CONFIG_FLAG_0x8629D05B = 22,
		_CPED_CONFIG_FLAG_0x1522968B = 23,
		CPED_CONFIG_FLAG_IgnoreSeenMelee = 24,
		_CPED_CONFIG_FLAG_0x4CC09C4B = 25,
		_CPED_CONFIG_FLAG_0x034F3053 = 26,
		_CPED_CONFIG_FLAG_0xD91BA7CC = 27,
		_CPED_CONFIG_FLAG_0x5C8DC66E = 28,
		_CPED_CONFIG_FLAG_0x8902EAA0 = 29,
		_CPED_CONFIG_FLAG_0x6580B9D2 = 30,
		_CPED_CONFIG_FLAG_0x0EF7A297 = 31,
		_CPED_CONFIG_FLAG_CanFlyThruWindscreen = 32, // 0x6BF86E5B
		CPED_CONFIG_FLAG_DieWhenRagdoll = 33,
		CPED_CONFIG_FLAG_HasHelmet = 34,
		CPED_CONFIG_FLAG_UseHelmet = 35,
		_CPED_CONFIG_FLAG_0xEEB3D630 = 36,
		_CPED_CONFIG_FLAG_0xB130D17B = 37,
		_CPED_CONFIG_FLAG_0x5F071200 = 38,
		CPED_CONFIG_FLAG_DisableEvasiveDives = 39,
		_CPED_CONFIG_FLAG_0xC287AAFF = 40,
		_CPED_CONFIG_FLAG_0x203328CC = 41,
		CPED_CONFIG_FLAG_DontInfluenceWantedLevel = 42,
		CPED_CONFIG_FLAG_DisablePlayerLockon = 43,
		CPED_CONFIG_FLAG_DisableLockonToRandomPeds = 44,
		_CPED_CONFIG_FLAG_0xEC4A8ACF = 45,
		_CPED_CONFIG_FLAG_0xDB115BFA = 46,
		CPED_CONFIG_FLAG_PedBeingDeleted = 47,
		CPED_CONFIG_FLAG_BlockWeaponSwitching = 48,
		_CPED_CONFIG_FLAG_0xF8E99565 = 49,
		_CPED_CONFIG_FLAG_0xDD17FEE6 = 50,
		_CPED_CONFIG_FLAG_0x7ED9B2C9 = 51,
		_CPED_CONFIG_FLAG_NoCollison = 52, // 0x655E8618
		_CPED_CONFIG_FLAG_0x5A6C1F6E = 53,
		_CPED_CONFIG_FLAG_0xD749FC41 = 54,
		_CPED_CONFIG_FLAG_0x357F63F3 = 55,
		_CPED_CONFIG_FLAG_0xC5E60961 = 56,
		_CPED_CONFIG_FLAG_0x29275C3E = 57,
		CPED_CONFIG_FLAG_IsFiring = 58,
		CPED_CONFIG_FLAG_WasFiring = 59,
		CPED_CONFIG_FLAG_IsStanding = 60,
		CPED_CONFIG_FLAG_WasStanding = 61,
		CPED_CONFIG_FLAG_InVehicle = 62,
		CPED_CONFIG_FLAG_OnMount = 63,
		CPED_CONFIG_FLAG_AttachedToVehicle = 64,
		CPED_CONFIG_FLAG_IsSwimming = 65,
		CPED_CONFIG_FLAG_WasSwimming = 66,
		CPED_CONFIG_FLAG_IsSkiing = 67,
		CPED_CONFIG_FLAG_IsSitting = 68,
		CPED_CONFIG_FLAG_KilledByStealth = 69,
		CPED_CONFIG_FLAG_KilledByTakedown = 70,
		CPED_CONFIG_FLAG_Knockedout = 71,
		_CPED_CONFIG_FLAG_0x3E3C4560 = 72,
		_CPED_CONFIG_FLAG_0x2994C7B7 = 73,
		_CPED_CONFIG_FLAG_0x6D59D275 = 74,
		CPED_CONFIG_FLAG_UsingCoverPoint = 75,
		CPED_CONFIG_FLAG_IsInTheAir = 76,
		_CPED_CONFIG_FLAG_0x2D493FB7 = 77,
		CPED_CONFIG_FLAG_IsAimingGun = 78,
		_CPED_CONFIG_FLAG_0x14D69875 = 79,
		_CPED_CONFIG_FLAG_0x40B05311 = 80,
		_CPED_CONFIG_FLAG_0x8B230BC5 = 81,
		_CPED_CONFIG_FLAG_0xC74E5842 = 82,
		_CPED_CONFIG_FLAG_0x9EA86147 = 83,
		_CPED_CONFIG_FLAG_0x674C746C = 84,
		_CPED_CONFIG_FLAG_0x3E56A8C2 = 85,
		_CPED_CONFIG_FLAG_0xC144A1EF = 86,
		_CPED_CONFIG_FLAG_0x0548512D = 87,
		_CPED_CONFIG_FLAG_0x31C93909 = 88,
		_CPED_CONFIG_FLAG_0xA0269315 = 89,
		_CPED_CONFIG_FLAG_0xD4D59D4D = 90,
		_CPED_CONFIG_FLAG_0x411D4420 = 91,
		_CPED_CONFIG_FLAG_0xDF4AEF0D = 92,
		CPED_CONFIG_FLAG_ForcePedLoadCover = 93,
		_CPED_CONFIG_FLAG_0x300E4CD3 = 94,
		_CPED_CONFIG_FLAG_0xF1C5BF04 = 95,
		_CPED_CONFIG_FLAG_0x89C2EF13 = 96,
		CPED_CONFIG_FLAG_VaultFromCover = 97,
		_CPED_CONFIG_FLAG_0x02A852C8 = 98,
		_CPED_CONFIG_FLAG_0x3D9407F1 = 99,
		_CPED_CONFIG_FLAG_IsDrunk = 100, // 0x319B4558
		CPED_CONFIG_FLAG_ForcedAim = 101,
		_CPED_CONFIG_FLAG_0xB942D71A = 102,
		_CPED_CONFIG_FLAG_0xD26C55A8 = 103,
		_CPED_CONFIG_FLAG_0xB89E703B = 104,
		CPED_CONFIG_FLAG_ForceReload = 105,
		_CPED_CONFIG_FLAG_0xD9E73DA2 = 106,
		_CPED_CONFIG_FLAG_0xFF71DC2C = 107,
		_CPED_CONFIG_FLAG_0x1E27E8D8 = 108,
		_CPED_CONFIG_FLAG_0xF2C53966 = 109,
		_CPED_CONFIG_FLAG_0xC4DBE247 = 110,
		_CPED_CONFIG_FLAG_0x83C0A4BF = 111,
		_CPED_CONFIG_FLAG_0x0E0FAF8C = 112,
		_CPED_CONFIG_FLAG_0x26616660 = 113,
		_CPED_CONFIG_FLAG_0x43B80B79 = 114,
		_CPED_CONFIG_FLAG_0x0D2A9309 = 115,
		_CPED_CONFIG_FLAG_0x12C1C983 = 116,
		CPED_CONFIG_FLAG_BumpedByPlayer = 117,
		_CPED_CONFIG_FLAG_0xE586D504 = 118,
		_CPED_CONFIG_FLAG_0x52374204 = 119,
		CPED_CONFIG_FLAG_IsHandCuffed = 120,
		CPED_CONFIG_FLAG_IsAnkleCuffed = 121,
		CPED_CONFIG_FLAG_DisableMelee = 122,
		_CPED_CONFIG_FLAG_0xFE714397 = 123,
		_CPED_CONFIG_FLAG_0xB3E660BD = 124,
		_CPED_CONFIG_FLAG_0x5FED6BFD = 125,
		_CPED_CONFIG_FLAG_0xC9D6F66F = 126,
		_CPED_CONFIG_FLAG_0x519BC986 = 127,
		CPED_CONFIG_FLAG_CanBeAgitated = 128,
		_CPED_CONFIG_FLAG_0x9A4B617C = 129,
		_CPED_CONFIG_FLAG_0xDAB70E9F = 130,
		_CPED_CONFIG_FLAG_0xE569438A = 131,
		_CPED_CONFIG_FLAG_0xBBC77D6D = 132,
		_CPED_CONFIG_FLAG_0xCB59EF0F = 133,
		_CPED_CONFIG_FLAG_0x8C5EA971 = 134,
		CPED_CONFIG_FLAG_IsScuba = 135,
		CPED_CONFIG_FLAG_WillArrestRatherThanJack = 136,
		_CPED_CONFIG_FLAG_0xDCE59B58 = 137,
		CPED_CONFIG_FLAG_RidingTrain = 138,
		CPED_CONFIG_FLAG_ArrestResult = 139,
		CPED_CONFIG_FLAG_CanAttackFriendly = 140,
		_CPED_CONFIG_FLAG_0x98A4BE43 = 141,
		_CPED_CONFIG_FLAG_0x6901E731 = 142,
		_CPED_CONFIG_FLAG_0x9EC9BF6C = 143,
		_CPED_CONFIG_FLAG_0x42841A8F = 144,
		CPED_CONFIG_FLAG_ShootingAnimFlag = 145,
		CPED_CONFIG_FLAG_DisableLadderClimbing = 146,
		CPED_CONFIG_FLAG_StairsDetected = 147,
		CPED_CONFIG_FLAG_SlopeDetected = 148,
		_CPED_CONFIG_FLAG_0x1A15670B = 149,
		_CPED_CONFIG_FLAG_0x61786EE5 = 150,
		_CPED_CONFIG_FLAG_0xCB9186BD = 151,
		_CPED_CONFIG_FLAG_0xF0710152 = 152,
		_CPED_CONFIG_FLAG_0x43DFE310 = 153,
		_CPED_CONFIG_FLAG_0xC43C624E = 154,
		CPED_CONFIG_FLAG_CanPerformArrest = 155,
		CPED_CONFIG_FLAG_CanPerformUncuff = 156,
		CPED_CONFIG_FLAG_CanBeArrested = 157,
		_CPED_CONFIG_FLAG_0xF7960FF5 = 158,
		_CPED_CONFIG_FLAG_0x59564113 = 159,
		_CPED_CONFIG_FLAG_0x0C6C3099 = 160,
		_CPED_CONFIG_FLAG_0x645F927A = 161,
		_CPED_CONFIG_FLAG_0xA86549B9 = 162,
		_CPED_CONFIG_FLAG_0x8AAF337A = 163,
		_CPED_CONFIG_FLAG_0x13BAA6E7 = 164,
		_CPED_CONFIG_FLAG_0x5FB9D1F5 = 165,
		CPED_CONFIG_FLAG_IsInjured = 166,
		_CPED_CONFIG_FLAG_0x6398A20B = 167,
		_CPED_CONFIG_FLAG_0xD8072639 = 168,
		_CPED_CONFIG_FLAG_0xA05B1845 = 169,
		_CPED_CONFIG_FLAG_0x83F6D220 = 170,
		_CPED_CONFIG_FLAG_0xD8430331 = 171,
		_CPED_CONFIG_FLAG_0x4B547520 = 172,
		_CPED_CONFIG_FLAG_0xE66E1406 = 173,
		_CPED_CONFIG_FLAG_0x1C4BFE0C = 174,
		_CPED_CONFIG_FLAG_0x90008BFA = 175,
		_CPED_CONFIG_FLAG_0x07C7A910 = 176,
		_CPED_CONFIG_FLAG_0xF15F8191 = 177,
		_CPED_CONFIG_FLAG_0xCE4E8BE2 = 178,
		_CPED_CONFIG_FLAG_0x1D46E4F2 = 179,
		CPED_CONFIG_FLAG_IsInCustody = 180,
		_CPED_CONFIG_FLAG_0xE4FD9B3A = 181,
		_CPED_CONFIG_FLAG_0x67AE0812 = 182,
		CPED_CONFIG_FLAG_IsAgitated = 183,
		CPED_CONFIG_FLAG_PreventAutoShuffleToDriversSeat = 184,
		_CPED_CONFIG_FLAG_0x7B2D325E = 185,
		CPED_CONFIG_FLAG_EnableWeaponBlocking = 186,
		CPED_CONFIG_FLAG_HasHurtStarted = 187,
		CPED_CONFIG_FLAG_DisableHurt = 188,
		CPED_CONFIG_FLAG_PlayerIsWeird = 189,
		_CPED_CONFIG_FLAG_0x32FC208B = 190,
		_CPED_CONFIG_FLAG_0x0C296E5A = 191,
		_CPED_CONFIG_FLAG_0xE63B73EC = 192,
		_CPED_CONFIG_FLAG_0x04E9CC80 = 193,
		CPED_CONFIG_FLAG_UsingScenario = 194,
		CPED_CONFIG_FLAG_VisibleOnScreen = 195,
		_CPED_CONFIG_FLAG_0xD88C58A1 = 196,
		_CPED_CONFIG_FLAG_0x5A3DCF43 = 197,
		_CPED_CONFIG_FLAG_0xEA02B420 = 198,
		_CPED_CONFIG_FLAG_0x3F559CFF = 199,
		_CPED_CONFIG_FLAG_0x8C55D029 = 200,
		_CPED_CONFIG_FLAG_0x5E6466F6 = 201,
		_CPED_CONFIG_FLAG_0xEB5AD706 = 202,
		_CPED_CONFIG_FLAG_0x0EDDDDE7 = 203,
		_CPED_CONFIG_FLAG_0xA64F7B1D = 204,
		_CPED_CONFIG_FLAG_0x48532CBA = 205,
		_CPED_CONFIG_FLAG_0xAA25A9E7 = 206,
		_CPED_CONFIG_FLAG_0x415B26B9 = 207,
		CPED_CONFIG_FLAG_DisableExplosionReactions = 208,
		CPED_CONFIG_FLAG_DodgedPlayer = 209,
		_CPED_CONFIG_FLAG_0x67405504 = 210,
		_CPED_CONFIG_FLAG_0x75DDD68C = 211,
		_CPED_CONFIG_FLAG_0x2AD879B4 = 212,
		_CPED_CONFIG_FLAG_0x51486F91 = 213,
		_CPED_CONFIG_FLAG_0x32F79E21 = 214,
		_CPED_CONFIG_FLAG_0xBF099213 = 215,
		_CPED_CONFIG_FLAG_0x054AC8E2 = 216,
		_CPED_CONFIG_FLAG_0x14E495CC = 217,
		_CPED_CONFIG_FLAG_0x3C7DF9DF = 218,
		_CPED_CONFIG_FLAG_0x848FFEF2 = 219,
		CPED_CONFIG_FLAG_DontEnterLeadersVehicle = 220,
		_CPED_CONFIG_FLAG_0x2618E1CF = 221,
		_CPED_CONFIG_FLAG_0x84F722FA = 222,
		_CPED_CONFIG_FLAG_Shrink = 223, // 0xD1B87B1F
		_CPED_CONFIG_FLAG_0x728AA918 = 224,
		CPED_CONFIG_FLAG_DisablePotentialToBeWalkedIntoResponse = 225,
		CPED_CONFIG_FLAG_DisablePedAvoidance = 226,
		_CPED_CONFIG_FLAG_0x59E91185 = 227,
		_CPED_CONFIG_FLAG_0x1EA7225F = 228,
		CPED_CONFIG_FLAG_DisablePanicInVehicle = 229,
		_CPED_CONFIG_FLAG_0x6DCA7D88 = 230,
		_CPED_CONFIG_FLAG_0xFC3E572D = 231,
		_CPED_CONFIG_FLAG_0x08E9F9CF = 232,
		_CPED_CONFIG_FLAG_0x2D3BA52D = 233,
		_CPED_CONFIG_FLAG_0xFD2F53EA = 234,
		_CPED_CONFIG_FLAG_0x31A1B03B = 235,
		CPED_CONFIG_FLAG_IsHoldingProp = 236,
		CPED_CONFIG_FLAG_BlocksPathingWhenDead = 237,
		_CPED_CONFIG_FLAG_0xCE57C9A3 = 238,
		_CPED_CONFIG_FLAG_0x26149198 = 239,
		_CPED_CONFIG_FLAG_0x1B33B598 = 240,
		_CPED_CONFIG_FLAG_0x719B6E87 = 241,
		_CPED_CONFIG_FLAG_0x13E8E8E8 = 242,
		_CPED_CONFIG_FLAG_0xF29739AE = 243,
		_CPED_CONFIG_FLAG_0xABEA8A74 = 244,
		_CPED_CONFIG_FLAG_0xB60EA2BA = 245,
		_CPED_CONFIG_FLAG_0x536B0950 = 246,
		_CPED_CONFIG_FLAG_0x0C754ACA = 247,
		CPED_CONFIG_FLAG_CanPlayInCarIdles = 248,
		_CPED_CONFIG_FLAG_0x12659168 = 249,
		_CPED_CONFIG_FLAG_0x1BDF2F04 = 250,
		_CPED_CONFIG_FLAG_0x7728FAA3 = 251,
		_CPED_CONFIG_FLAG_0x6A807ED8 = 252,
		CPED_CONFIG_FLAG_OnStairs = 253,
		_CPED_CONFIG_FLAG_0xE1A2F73F = 254,
		_CPED_CONFIG_FLAG_0x5B3697C8 = 255,
		_CPED_CONFIG_FLAG_0xF1EB20A9 = 256,
		_CPED_CONFIG_FLAG_0x8B7DF407 = 257,
		_CPED_CONFIG_FLAG_0x329DCF1A = 258,
		_CPED_CONFIG_FLAG_0x8D90DD1B = 259,
		_CPED_CONFIG_FLAG_0xB8A292B7 = 260,
		_CPED_CONFIG_FLAG_0x8374B087 = 261,
		_CPED_CONFIG_FLAG_0x2AF558F0 = 262,
		_CPED_CONFIG_FLAG_0x82251455 = 263,
		_CPED_CONFIG_FLAG_0x30CF498B = 264,
		_CPED_CONFIG_FLAG_0xE1CD50AF = 265,
		_CPED_CONFIG_FLAG_0x72E4AE48 = 266,
		_CPED_CONFIG_FLAG_0xC2657EA1 = 267,
		_CPED_CONFIG_FLAG_0x29FF6030 = 268,
		_CPED_CONFIG_FLAG_0x8248A5EC = 269,
		CPED_CONFIG_FLAG_OnStairSlope = 270,
		_CPED_CONFIG_FLAG_0xA0897933 = 271,
		CPED_CONFIG_FLAG_DontBlipCop = 272,
		CPED_CONFIG_FLAG_ClimbedShiftedFence = 273,
		_CPED_CONFIG_FLAG_0xF7823618 = 274,
		_CPED_CONFIG_FLAG_0xDC305CCE = 275,
		CPED_CONFIG_FLAG_EdgeDetected = 276,
		_CPED_CONFIG_FLAG_0x92B67896 = 277,
		_CPED_CONFIG_FLAG_0xCAD677C9 = 278,
		CPED_CONFIG_FLAG_AvoidTearGas = 279,
		_CPED_CONFIG_FLAG_0x5276AC7B = 280,
		_CPED_CONFIG_FLAG_NoWrithe = 281, // 0x1032692A
		_CPED_CONFIG_FLAG_0xDA23E7F1 = 282,
		_CPED_CONFIG_FLAG_0x9139724D = 283,
		_CPED_CONFIG_FLAG_0xA1457461 = 284,
		_CPED_CONFIG_FLAG_0x4186E095 = 285,
		_CPED_CONFIG_FLAG_0xAC68E2EB = 286,
		CPED_CONFIG_FLAG_RagdollingOnBoat = 287,
		CPED_CONFIG_FLAG_HasBrandishedWeapon = 288,
		_CPED_CONFIG_FLAG_0x1B9EE8A1 = 289,
		_CPED_CONFIG_FLAG_0xF3F5758C = 290,
		_CPED_CONFIG_FLAG_0x2A9307F1 = 291,
		_CPED_CONFIG_FLAG_FreezePosition = 292, // 0x7403D216
		_CPED_CONFIG_FLAG_0xA06A3C6C = 293,
		CPED_CONFIG_FLAG_DisableShockingEvents = 294,
		_CPED_CONFIG_FLAG_0xF8DA25A5 = 295,
		_CPED_CONFIG_FLAG_0x7EF55802 = 296,
		_CPED_CONFIG_FLAG_0xB31F1187 = 297,
		_CPED_CONFIG_FLAG_0x84315402 = 298,
		_CPED_CONFIG_FLAG_0x0FD69867 = 299,
		_CPED_CONFIG_FLAG_0xC7829B67 = 300,
		CPED_CONFIG_FLAG_DisablePedConstraints = 301,
		_CPED_CONFIG_FLAG_0x6D23CF25 = 302,
		_CPED_CONFIG_FLAG_0x2ADA871B = 303,
		_CPED_CONFIG_FLAG_0x47BC8A58 = 304,
		_CPED_CONFIG_FLAG_0xEB692FA5 = 305,
		_CPED_CONFIG_FLAG_0x4A133C50 = 306,
		_CPED_CONFIG_FLAG_0xC58099C3 = 307,
		_CPED_CONFIG_FLAG_0xF3D76D41 = 308,
		_CPED_CONFIG_FLAG_0xB0EEE9F2 = 309,
		CPED_CONFIG_FLAG_IsInCluster = 310,
		_CPED_CONFIG_FLAG_0x0FA153EF = 311,
		_CPED_CONFIG_FLAG_0xD73F5CD3 = 312,
		_CPED_CONFIG_FLAG_0xD4136C22 = 313,
		_CPED_CONFIG_FLAG_0xE404CA6B = 314,
		_CPED_CONFIG_FLAG_0xB9597446 = 315,
		_CPED_CONFIG_FLAG_0xD5C98277 = 316,
		_CPED_CONFIG_FLAG_0xD5060A9C = 317,
		_CPED_CONFIG_FLAG_0x3E5F1CBB = 318,
		_CPED_CONFIG_FLAG_0xD8BE1D54 = 319,
		_CPED_CONFIG_FLAG_0x0B1F191F = 320,
		_CPED_CONFIG_FLAG_0xC995167A = 321,
		CPED_CONFIG_FLAG_HasHighHeels = 322,
		_CPED_CONFIG_FLAG_0x86B01E54 = 323,
		_CPED_CONFIG_FLAG_0x3A56FE15 = 324,
		_CPED_CONFIG_FLAG_0xC03B736C = 325, // SpawnedAtScenario?
		_CPED_CONFIG_FLAG_0xBBF47729 = 326,
		_CPED_CONFIG_FLAG_0x22B668A8 = 327,
		_CPED_CONFIG_FLAG_0x2624D4D4 = 328,
		CPED_CONFIG_FLAG_DisableTalkTo = 329,
		CPED_CONFIG_FLAG_DontBlip = 330,
		CPED_CONFIG_FLAG_IsSwitchingWeapon = 331,
		_CPED_CONFIG_FLAG_0x630F55F3 = 332,
		_CPED_CONFIG_FLAG_0x150468FD = 333,
		_CPED_CONFIG_FLAG_0x914EBD6B = 334,
		_CPED_CONFIG_FLAG_0x79AF3B6D = 335,
		_CPED_CONFIG_FLAG_0x75C7A632 = 336,
		_CPED_CONFIG_FLAG_0x52D530E2 = 337,
		_CPED_CONFIG_FLAG_0xDB2A90E0 = 338,
		_CPED_CONFIG_FLAG_0x5922763D = 339,
		_CPED_CONFIG_FLAG_0x12ADB567 = 340,
		_CPED_CONFIG_FLAG_0x105C8518 = 341,
		_CPED_CONFIG_FLAG_0x106F703D = 342,
		_CPED_CONFIG_FLAG_0xED152C3E = 343,
		_CPED_CONFIG_FLAG_0xA0EFE6A8 = 344,
		_CPED_CONFIG_FLAG_0xBF348C82 = 345,
		_CPED_CONFIG_FLAG_0xCDDFE830 = 346,
		_CPED_CONFIG_FLAG_0x7B59BD9B = 347,
		_CPED_CONFIG_FLAG_0x0124C788 = 348,
		CPED_CONFIG_FLAG_EquipJetpack = 349,
		_CPED_CONFIG_FLAG_0x08D361A5 = 350,
		_CPED_CONFIG_FLAG_0xE13D1F7C = 351,
		_CPED_CONFIG_FLAG_0x40E25FB9 = 352,
		_CPED_CONFIG_FLAG_0x930629D9 = 353,
		_CPED_CONFIG_FLAG_0xECCF0C7F = 354,
		_CPED_CONFIG_FLAG_0xB6E9613B = 355,
		_CPED_CONFIG_FLAG_0x490C0478 = 356,
		_CPED_CONFIG_FLAG_0xE8865BEA = 357,
		_CPED_CONFIG_FLAG_0xF3C34A29 = 358,
		CPED_CONFIG_FLAG_IsDuckingInVehicle = 359,
		_CPED_CONFIG_FLAG_0xF660E115 = 360,
		_CPED_CONFIG_FLAG_0xAB0E6DED = 361,
		CPED_CONFIG_FLAG_HasReserveParachute = 362,
		CPED_CONFIG_FLAG_UseReserveParachute = 363,
		_CPED_CONFIG_FLAG_0x5C5D9CD3 = 364,
		_CPED_CONFIG_FLAG_0x8F7701F3 = 365,
		_CPED_CONFIG_FLAG_0xBC4436AD = 366,
		_CPED_CONFIG_FLAG_0xD7E07D37 = 367,
		_CPED_CONFIG_FLAG_0x03C4FD24 = 368,
		_CPED_CONFIG_FLAG_0x7675789A = 369,
		_CPED_CONFIG_FLAG_0xB7288A88 = 370,
		_CPED_CONFIG_FLAG_0xC06B6291 = 371,
		_CPED_CONFIG_FLAG_0x95A4A805 = 372,
		_CPED_CONFIG_FLAG_0xA8E9A042 = 373,
		CPED_CONFIG_FLAG_NeverLeaveTrain = 374,
		_CPED_CONFIG_FLAG_0xBAC674B3 = 375,
		_CPED_CONFIG_FLAG_0x147F1FFB = 376,
		_CPED_CONFIG_FLAG_0x4376DD79 = 377,
		_CPED_CONFIG_FLAG_0xCD3DB518 = 378,
		_CPED_CONFIG_FLAG_0xFE4BA4B6 = 379,
		_CPED_CONFIG_FLAG_0x5DF03A55 = 380,
		_CPED_CONFIG_FLAG_0xBCD816CD = 381,
		_CPED_CONFIG_FLAG_0xCF02DD69 = 382,
		_CPED_CONFIG_FLAG_0xF73AFA2E = 383,
		_CPED_CONFIG_FLAG_0x80B9A9D0 = 384,
		_CPED_CONFIG_FLAG_0xF601F7EE = 385,
		_CPED_CONFIG_FLAG_0xA91350FC = 386,
		_CPED_CONFIG_FLAG_0x3AB23B96 = 387,
		CPED_CONFIG_FLAG_IsClimbingLadder = 388,
		CPED_CONFIG_FLAG_HasBareFeet = 389,
		_CPED_CONFIG_FLAG_0xB4B1CD4C = 390,
		_CPED_CONFIG_FLAG_0x5459AFB8 = 391,
		_CPED_CONFIG_FLAG_0x54F27667 = 392,
		_CPED_CONFIG_FLAG_0xC11D3E8F = 393,
		_CPED_CONFIG_FLAG_0x5419EB3E = 394,
		_CPED_CONFIG_FLAG_0x82D8DBB4 = 395,
		_CPED_CONFIG_FLAG_0x33B02D2F = 396,
		_CPED_CONFIG_FLAG_0xAE66176D = 397,
		_CPED_CONFIG_FLAG_0xA2692593 = 398,
		_CPED_CONFIG_FLAG_0x714C7E31 = 399,
		_CPED_CONFIG_FLAG_0xEC488AC7 = 400,
		_CPED_CONFIG_FLAG_0xAE398504 = 401,
		_CPED_CONFIG_FLAG_0xABC58D72 = 402,
		_CPED_CONFIG_FLAG_0x5E5B9591 = 403,
		_CPED_CONFIG_FLAG_0x6BA1091E = 404,
		_CPED_CONFIG_FLAG_0x77840177 = 405,
		_CPED_CONFIG_FLAG_0x1C7ACAC4 = 406,
		_CPED_CONFIG_FLAG_0x124420E9 = 407,
		_CPED_CONFIG_FLAG_0x75A65587 = 408,
		_CPED_CONFIG_FLAG_0xDFD2D55B = 409,
		_CPED_CONFIG_FLAG_0xBDD39919 = 410,
		_CPED_CONFIG_FLAG_0x43DEC267 = 411,
		_CPED_CONFIG_FLAG_0xE42B7797 = 412,
		CPED_CONFIG_FLAG_IsHolsteringWeapon = 413,
		_CPED_CONFIG_FLAG_0x4F8149F5 = 414,
		_CPED_CONFIG_FLAG_0xDD9ECA7A = 415,
		_CPED_CONFIG_FLAG_0x9E7EF9D2 = 416,
		_CPED_CONFIG_FLAG_0x2C6ED942 = 417,
		CPED_CONFIG_FLAG_IsSwitchingHelmetVisor = 418,
		_CPED_CONFIG_FLAG_0xA488727D = 419,
		_CPED_CONFIG_FLAG_0xCFF5F6DE = 420,
		_CPED_CONFIG_FLAG_0x6D614599 = 421,
		CPED_CONFIG_FLAG_DisableVehicleCombat = 422,
		_CPED_CONFIG_FLAG_0xFE401D26 = 423,
		CPED_CONFIG_FLAG_FallsLikeAircraft = 424,
		_CPED_CONFIG_FLAG_0x2B42AE82 = 425,
		_CPED_CONFIG_FLAG_0x7A95734F = 426,
		_CPED_CONFIG_FLAG_0xDF4D8617 = 427,
		_CPED_CONFIG_FLAG_0x578F1F14 = 428,
		CPED_CONFIG_FLAG_DisableStartEngine = 429,
		CPED_CONFIG_FLAG_IgnoreBeingOnFire = 430,
		_CPED_CONFIG_FLAG_0x153C9500 = 431,
		_CPED_CONFIG_FLAG_0xCB7A632E = 432,
		_CPED_CONFIG_FLAG_0xDE727981 = 433,
		CPED_CONFIG_FLAG_DisableHomingMissileLockon = 434,
		_CPED_CONFIG_FLAG_0x12BBB935 = 435,
		_CPED_CONFIG_FLAG_0xAD0A1277 = 436,
		_CPED_CONFIG_FLAG_0xEA6AA46A = 437,
		CPED_CONFIG_FLAG_DisableHelmetArmor = 438,
		_CPED_CONFIG_FLAG_0xCB7F3A1E = 439,
		_CPED_CONFIG_FLAG_0x50178878 = 440,
		_CPED_CONFIG_FLAG_0x051B4F0D = 441,
		_CPED_CONFIG_FLAG_0x2FC3DECC = 442,
		_CPED_CONFIG_FLAG_0xC0030B0B = 443,
		_CPED_CONFIG_FLAG_0xBBDAF1E9 = 444,
		_CPED_CONFIG_FLAG_0x944FE59C = 445,
		_CPED_CONFIG_FLAG_0x506FBA39 = 446,
		_CPED_CONFIG_FLAG_0xDD45FE84 = 447,
		_CPED_CONFIG_FLAG_0xE698AE75 = 448,
		_CPED_CONFIG_FLAG_0x199633F8 = 449,
		CPED_CONFIG_FLAG_PedIsArresting = 450,
		CPED_CONFIG_FLAG_IsDecoyPed = 451,
		_CPED_CONFIG_FLAG_0x3A251D83 = 452,
		_CPED_CONFIG_FLAG_0xA56F6986 = 453,
		_CPED_CONFIG_FLAG_0x1D19C622 = 454,
		_CPED_CONFIG_FLAG_0xB68D3EAB = 455,
		CPED_CONFIG_FLAG_CanBeIncapacitated = 456,
		_CPED_CONFIG_FLAG_0x4BD5EBAD = 457,
		_CPED_CONFIG_FLAG_0xFCC5EBC5 = 458
	};

	// PS4 dump. From maybegreat48.
	enum class KickReason : std::uint8_t
	{
		VOTED_OUT,
		PEER_COMPLAINTS,
		CONNECTION_ERROR,
		NAT_TYPE,
		SCADMIN,
		SCADMIN_BLACKLIST,
		NUM_REASONS
	};

	enum class eCollectibleType // Skidded from maybegreat48.
	{
		MovieProp = 0,
		CacheShard = 1,
		ChestShard = 2,
		RadioTowerShard = 3,
		AudioPlayerShard = 4,
		ShipwreckShard = 5,
		BuriedStashShard = 6,
		Treat = 8,
		Organics = 9,
		Skydive = 10
	};
	
	enum ePlayerStatType // Skidded from gir489
	{
		RP = 1,
		MoneyCash = 3,
		GlobalRP = 5,
		Rank = 6,
		KDRatio = 26,
		Kills = 28,
		Deaths = 29,
		CanSpectate = 52,
		FavoriteRadio = 53,
		MoneyAll = 56,
	};
}
