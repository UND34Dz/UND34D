#include "common.hpp"
#include "core/globals.hpp"
#include "fiber_pool.hpp"
#include "gui.hpp"
#include "logger.hpp"
#include "hooking.hpp"
#include "pointers.hpp"
#include "renderer.hpp"
#include "script_mgr.hpp"
#include "thread_pool.hpp"
#include "shv_runner.h"
#include "asi_loader/asi_scripts.h"

#include "backend/backend.hpp"
#include "native_hooks/native_hooks.hpp"
#include "services/anti_cheat/anti_cheat_service.hpp"
#include "services/chat/chat_service.hpp"
#include "services/context_menu/context_menu_service.hpp"
#include "services/custom_text/custom_text_service.hpp"
#include "services/globals/globals_service.hpp"
#include "services/gta_data/gta_data_service.hpp"
#include "services/mobile/mobile_service.hpp"
#include "services/pickups/pickup_service.hpp"
#include "services/players/player_service.hpp"
#include "services/player_database/player_database_service.hpp"
#include "services/notifications/notification_service.hpp"
#include "services/spinner/spinner_service.hpp"
#include "services/model_preview/model_preview_service.hpp"
#include "services/vehicle/handling_service.hpp"
#include "gui/ytd loader/ytd_loader.hpp"
BOOL APIENTRY DllMain(HMODULE hmod, DWORD reason, PVOID)
{
	using namespace big;
	if (reason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hmod);

		g_hmodule = hmod;
		g_is_steam = GetModuleHandle(L"steam_api64.dll") != NULL;
		g_main_thread = CreateThread(nullptr, 0, [](PVOID) -> DWORD
		{
			bool cant_find_window;
			while (!FindWindow(L"grcWindow", L"Grand Theft Auto V"))
			{
				cant_find_window = true;
				std::this_thread::sleep_for(1s);
			}

			if(cant_find_window)
				std::this_thread::sleep_for(20s);

			g_hwnd = FindWindow(L"grcWindow", L"Grand Theft Auto V");
			std::filesystem::path base_dir = std::getenv("appdata");
			base_dir /= "UND34D";
			auto file_manager_instance = std::make_unique<file_manager>(base_dir);

			auto globals_instance = std::make_unique<menu_settings>(
				file_manager_instance->get_project_file("./settings.json")
			);

			g->load();
			auto logger_instance = std::make_unique<logger>(
				"UND34D",
				file_manager_instance->get_project_file("./cout.log")
				);

			EnableMenuItem(GetSystemMenu(GetConsoleWindow(), 0), SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);

			try
			{
				LOG(INFO) << "UND34D Initializing";

				LOG(INFO) << "Settings Loaded.";

				auto pointers_instance = std::make_unique<pointers>();
				LOG(INFO) << "Pointers initialized.";

				auto renderer_instance = std::make_unique<renderer>();
				LOG(INFO) << "Renderer initialized.";

				auto fiber_pool_instance = std::make_unique<fiber_pool>(11);
				LOG(INFO) << "Fiber pool initialized.";

				auto hooking_instance = std::make_unique<hooking>();
				LOG(INFO) << "Hooking initialized.";

				//auto ytd_loader = std::make_unique<YTDLoader>();
				//g_YtdLoader = std::make_unique<YTDLoader>();
				LOG(INFO) << "YTD initialized.";

				auto thread_pool_instance = std::make_unique<thread_pool>();
				LOG(INFO) << "Thread pool initialized.";

				auto anti_cheat_service_instance = std::make_unique<anti_cheat_service>();
				auto chat_service_instance = std::make_unique<chat_service>();
				auto context_menu_service_instance = std::make_unique<context_menu_service>();
				auto custom_text_service_instance = std::make_unique<custom_text_service>();
				auto globals_service_instace = std::make_unique<globals_service>();
				auto mobile_service_instance = std::make_unique<mobile_service>();
				auto notification_service_instance = std::make_unique<notification_service>();
				auto spinner_service_instance = std::make_unique<spinner_service>();
				auto pickup_service_instance = std::make_unique<pickup_service>();
				auto player_service_instance = std::make_unique<player_service>();
				auto player_database_service_instance = std::make_unique<player_database_service>();
				auto gta_data_service_instance = std::make_unique<gta_data_service>();
				auto model_preview_service_instance = std::make_unique<model_preview_service>();
				auto handling_service_instance = std::make_unique<handling_service>();
				LOG(INFO) << "Registered service instances...";

				g_script_mgr.add_script(std::make_unique<script>(&gui::script_func, "GUI", false));
				g_script_mgr.add_script(std::make_unique<script>(&shv_runner::script_func));
				
				g_script_mgr.add_script(std::make_unique<script>(&backend::loop, "Backend Loop", false));
				g_script_mgr.add_script(std::make_unique<script>(&backend::anti_cheat, "Anti-Cheat Loop"));
				g_script_mgr.add_script(std::make_unique<script>(&backend::self_loop, "Self"));
				g_script_mgr.add_script(std::make_unique<script>(&backend::weapons_loop, "Weapon"));
				g_script_mgr.add_script(std::make_unique<script>(&backend::vehicles_loop, "Vehicle"));
				g_script_mgr.add_script(std::make_unique<script>(&backend::misc_loop, "Miscellaneous"));
				g_script_mgr.add_script(std::make_unique<script>(&backend::remote_loop, "Remote"));
				g_script_mgr.add_script(std::make_unique<script>(&backend::noclip_loop, "No Clip"));
				g_script_mgr.add_script(std::make_unique<script>(&backend::lscustoms_loop, "LS Customs"));
				g_script_mgr.add_script(std::make_unique<script>(&backend::rainbowpaint_loop, "Rainbow Paint"));
				g_script_mgr.add_script(std::make_unique<script>(&backend::vehiclefly_loop, "Vehicle Fly"));
				g_script_mgr.add_script(std::make_unique<script>(&backend::turnsignal_loop, "Turn Signals"));
				g_script_mgr.add_script(std::make_unique<script>(&backend::hotkeys_input, "Hotkeys Input"));
				g_script_mgr.add_script(std::make_unique<script>(&backend::hotkeys_loop, "Hotkeys Loop"));
				g_script_mgr.add_script(std::make_unique<script>(&backend::disable_control_action_loop, "Disable Controls"));
				g_script_mgr.add_script(std::make_unique<script>(&context_menu_service::context_menu, "Context Menu"));
				g_script_mgr.add_script(std::make_unique<script>(&chat_service::chat_menu, "Chat Menu"));
				LOG(INFO) << "Scripts registered.";

				auto native_hooks_instance = std::make_unique<native_hooks>();
				LOG(INFO) << "Dynamic native hooker initialized.";

				g_hooking->enable();
				LOG(INFO) << "Hooking enabled.";

					g_running = true;
					ASILoader::Initialize();
					LOG(INFO) << "ASI Loader initialized.";

				while (g_running)
					std::this_thread::sleep_for(500ms);

				shv_runner::shutdown();
				LOG(INFO) << "ASI plugins unloaded.";

				g_hooking->disable();
				LOG(INFO) << "Hooking disabled.";

				native_hooks_instance.reset();
				LOG(INFO) << "Dynamic native hooker uninitialized.";

				g_script_mgr.remove_all_scripts();
				LOG(INFO) << "Scripts unregistered.";

				// Make sure that all threads created don't have any blocking loops
				// otherwise make sure that they have stopped executing
				thread_pool_instance->destroy();
				LOG(INFO) << "Destroyed thread pool.";

				thread_pool_instance.reset();
				LOG(INFO) << "Thread pool uninitialized.";

				anti_cheat_service_instance.reset();
				LOG(INFO) << "Anti-Cheat Service reset.";
				chat_service_instance.reset();
				LOG(INFO) << "Chat Service reset.";
				gta_data_service_instance.reset();
				LOG(INFO) << "GTA Data Service reset.";
				handling_service_instance.reset();
				LOG(INFO) << "Vehicle Service reset.";
				model_preview_service_instance.reset();
				LOG(INFO) << "Model Preview Service reset.";
				mobile_service_instance.reset();
				LOG(INFO) << "Mobile Service reset.";
				spinner_service_instance.reset();
				LOG(INFO) << "Spinner Service reset.";
				player_service_instance.reset();
				LOG(INFO) << "Player Service reset.";
				player_database_service_instance.reset();
				LOG(INFO) << "Player Database Service reset.";
				pickup_service_instance.reset();
				LOG(INFO) << "Pickup Service reset.";
				globals_service_instace.reset();
				LOG(INFO) << "Globals Service reset.";
				custom_text_service_instance.reset();
				LOG(INFO) << "Custom Text Service reset.";
				context_menu_service_instance.reset();
				LOG(INFO) << "Context Service reset.";
				LOG(INFO) << "Services uninitialized.";

			//	ytd_loader.reset();

				hooking_instance.reset();
				LOG(INFO) << "Hooking uninitialized.";

				fiber_pool_instance.reset();
				LOG(INFO) << "Fiber pool uninitialized.";

				renderer_instance.reset();
				LOG(INFO) << "Renderer uninitialized.";

				pointers_instance.reset();
				LOG(INFO) << "Pointers uninitialized.";
			}
			catch (std::exception const& ex)
			{
				LOG(WARNING) << ex.what();
			}

			LOG(INFO) << "Farewell!";
			logger_instance->destroy();
			logger_instance.reset();

			globals_instance.reset();

			file_manager_instance.reset();

			CloseHandle(g_main_thread);
			FreeLibraryAndExitThread(g_hmodule, 0);
		}, nullptr, 0, &g_main_thread_id);
	}

	return true;
}
