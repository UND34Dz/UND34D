#include "views/view.hpp"
#include "natives.hpp"
#include "fiber_pool.hpp"
#include "widgets/imgui_piemenu.hpp"
#include "util/mobile.hpp"
#include "util/ped.hpp"

namespace big
{
    void view::pie_menu()
    {
        ImGui::OpenPopup("PieMenu");

        if (ImGui::BeginPiePopup("Utility Wheel", 1))
        {
            if (ImGui::BeginPieMenu("Animations"))
            {
                if (ImGui::PieMenuItem("In The Hood")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        ped::play_anim(self::ped, "missfbi3_sniping", "dance_m_default", 1);
                    } QUEUE_JOB_END_CLAUSE
                }

                if (ImGui::PieMenuItem("Arms Crossed")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        ped::play_anim(self::ped, "missdocksshowoffcar@idle_a", "idle_b_5", 1);
                    } QUEUE_JOB_END_CLAUSE
                }

                if (ImGui::PieMenuItem("Kicking Guy 1")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        ped::play_anim(self::ped, "missheistdockssetup1ig_13@kick_idle", "guard_beatup_kickidle_guard1", 1);
                    } QUEUE_JOB_END_CLAUSE
                }

                if (ImGui::PieMenuItem("Kicking Guy 2")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        ped::play_anim(self::ped, "missheistdockssetup1ig_13@kick_idle", "guard_beatup_kickidle_guard2", 1);
                    } QUEUE_JOB_END_CLAUSE
                }

                if (ImGui::PieMenuItem("Kick Rocks")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        ped::play_anim(self::ped, "timetable@ron@ig_1", "ig_1_idle_a", 1);
                    } QUEUE_JOB_END_CLAUSE
                }

                if (ImGui::PieMenuItem("Examining")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        ped::play_anim(self::ped, "missfbi5ig_15", "look_into_microscope_c_scientistb", 1);
                    } QUEUE_JOB_END_CLAUSE
                }

                if (ImGui::PieMenuItem("Drunk")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        ped::play_anim(self::ped, "move_m@drunk@verydrunk_idles@", "fidget_01", 1);
                    } QUEUE_JOB_END_CLAUSE
                }

                if (ImGui::PieMenuItem("Ow, My Head")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        ped::play_anim(self::ped, "misscarsteal4@actor", "dazed_idle", 1);
                    } QUEUE_JOB_END_CLAUSE
                }

                ImGui::EndPieMenu();
            }
            if (ImGui::BeginPieMenu("Tasks"))
            {
                if (ImGui::PieMenuItem("Clear Task")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        TASK::CLEAR_PED_TASKS(self::ped);
                    } QUEUE_JOB_END_CLAUSE
                }
                
                if (ImGui::PieMenuItem("Clear Task Force")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        TASK::CLEAR_PED_TASKS_IMMEDIATELY(self::ped);
                    } QUEUE_JOB_END_CLAUSE
                }

                ImGui::EndPieMenu();
            }
            if (ImGui::BeginPieMenu("Phone"))
            {
                if (ImGui::BeginPieMenu("Requests"))
                {
                    if (ImGui::PieMenuItem("MOC")) {
                        *script_global(2810701).at(913).as<int*>() = 1;
                    }

                    if (ImGui::PieMenuItem("Avenger")) {
                        *script_global(2810701).at(921).as<int*>() = 1;
                    }
                    if (ImGui::PieMenuItem("Terrobyte")) {
                        *script_global(2810701).at(925).as<int*>() = 1;
                    }

                    if (ImGui::PieMenuItem("Kosatka")) {
                        *script_global(2810701).at(933).as<int*>() = 1;
                    }

                    if (ImGui::PieMenuItem("Ballistic Armor")) {
                        *script_global(2810701).at(884).as<int*>() = 1;
                    }
                    ImGui::EndPieMenu();
                }
                if (ImGui::PieMenuItem("Lester Off Radar")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        mobile::lester::off_radar(1);
                    } QUEUE_JOB_END_CLAUSE
                }
                
                if (ImGui::PieMenuItem("Mors Mutual Fix All")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        mobile::mors_mutual::fix_all();
                    } QUEUE_JOB_END_CLAUSE
                }

                ImGui::EndPieMenu();
            }
            if (ImGui::BeginPieMenu("Ped"))
            {
                if (ImGui::BeginPieMenu("Walk Styles"))
                {
                    if (ImGui::PieMenuItem("Heavy")) {
                        QUEUE_JOB_BEGIN_CLAUSE() {
                            PED::SET_PED_MOVEMENT_CLIPSET(self::ped, "ANIM_GROUP_MOVE_BALLISTIC", 1.0f);
                        } QUEUE_JOB_END_CLAUSE
                    }
                    
                    if (ImGui::PieMenuItem("Lester 1")) {
                        QUEUE_JOB_BEGIN_CLAUSE() {
                            PED::SET_PED_MOVEMENT_CLIPSET(self::ped, "move_heist_lester", 1.0f);
                        } QUEUE_JOB_END_CLAUSE
                    }

                    if (ImGui::PieMenuItem("Lester 2")) {
                        QUEUE_JOB_BEGIN_CLAUSE() {
                            PED::SET_PED_MOVEMENT_CLIPSET(self::ped, "move_lester_CaneUp", 1.0f);
                        } QUEUE_JOB_END_CLAUSE
                    }

                    if (ImGui::PieMenuItem("Injured")) {
                        QUEUE_JOB_BEGIN_CLAUSE() {
                            PED::SET_PED_MOVEMENT_CLIPSET(self::ped, "move_injured_generic", 1.0f);
                        } QUEUE_JOB_END_CLAUSE
                    }

                    if (ImGui::PieMenuItem("Drunk")) {
                        QUEUE_JOB_BEGIN_CLAUSE() {
                            PED::SET_PED_MOVEMENT_CLIPSET(self::ped, "MOVE_M@DRUNK@VERYDRUNK", 1.0f);
                        } QUEUE_JOB_END_CLAUSE
                    }

                    if (ImGui::PieMenuItem("Crouched")) {
                        QUEUE_JOB_BEGIN_CLAUSE() {
                            PED::SET_PED_MOVEMENT_CLIPSET(self::ped, "move_ped_crouched", 0.5f);
                            PED::SET_PED_STRAFE_CLIPSET(self::ped, "move_ped_crouched_strafing");
                        } QUEUE_JOB_END_CLAUSE
                    }

                    if (ImGui::PieMenuItem("Femme")) {
                        QUEUE_JOB_BEGIN_CLAUSE() {
                            PED::SET_PED_MOVEMENT_CLIPSET(self::ped, "MOVE_F@FEMME@", 1.0f);
                        } QUEUE_JOB_END_CLAUSE
                    }

                    if (ImGui::PieMenuItem("Reset")) {
                        QUEUE_JOB_BEGIN_CLAUSE() {
                            PED::RESET_PED_MOVEMENT_CLIPSET(self::ped, 0.0f);
                            PED::RESET_PED_STRAFE_CLIPSET(self::ped);
                        } QUEUE_JOB_END_CLAUSE
                    }

                    ImGui::EndPieMenu();
                }

                if (ImGui::PieMenuItem("Ragdoll")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        PED::SET_PED_TO_RAGDOLL(self::ped, 0, 1000, 0, 0, 1, 0);
                    } QUEUE_JOB_END_CLAUSE
                }

                if (ImGui::PieMenuItem("Max Health")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        ENTITY::SET_ENTITY_HEALTH(self::ped, ENTITY::GET_ENTITY_MAX_HEALTH(self::ped), 0);
                    } QUEUE_JOB_END_CLAUSE
                }

                if (ImGui::PieMenuItem("Max Armor")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        PED::SET_PED_ARMOUR(self::ped, 100);
                    } QUEUE_JOB_END_CLAUSE
                }

                ImGui::EndPieMenu();
            }
            if (ImGui::BeginPieMenu("RC Vehicles"))
            {
                if (ImGui::PieMenuItem("RC Tank")) {
                    *script_global(2810701).at(6709).as<int*>() = 1;
                }

                if (ImGui::PieMenuItem("RC Bandito")) {
                    *script_global(2810701).at(6708).as<int*>() = 1;
                }
                if (ImGui::PieMenuItem("Drone")) {
                    LOG(INFO) << "Not implemented";
                }

                ImGui::EndPieMenu();
            }

            if (ImGui::BeginPieMenu("PvP"))
            {
                if (ImGui::PieMenuItem("Drop BST")) {
                        //ENTITY::SET_ENTITY_HEALTH(self::ped, ENTITY::GET_ENTITY_MAX_HEALTH(self::ped), 0);
                }

                if (ImGui::PieMenuItem("Drop Armor")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        PED::SET_PED_ARMOUR(self::ped, 100);
                    } QUEUE_JOB_END_CLAUSE
                }
                ImGui::EndPieMenu();
            }

            if (ImGui::BeginPieMenu("Dev"))
            {
                if (ImGui::PieMenuItem("Fade Id")) {
                    if (CAM::IS_SCREEN_FADED_OUT())
                        CAM::DO_SCREEN_FADE_IN(100);
                }

                if (ImGui::PieMenuItem("SP Map")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        DLC::ON_ENTER_SP();
                    } QUEUE_JOB_END_CLAUSE
                }

                if (ImGui::PieMenuItem("MP Map")) {
                    QUEUE_JOB_BEGIN_CLAUSE() {
                        DLC::ON_ENTER_MP();
                    } QUEUE_JOB_END_CLAUSE
                }
                ImGui::EndPieMenu();
            }

            ImGui::EndPiePopup();
        }
    }
}