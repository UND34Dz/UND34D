#include "backend/looped/looped.hpp"
#include "natives.hpp"
#include "services/players/player_service.hpp"

namespace big
{
	void looped::tunables_disablehud() {
		if (g->tunables.disablehud) {
			HUD::HIDE_HUD_AND_RADAR_THIS_FRAME();
		}
		else
		{
			return;
		}
	}
}