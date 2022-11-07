#include "backend/looped/looped.hpp"
#include "natives.hpp"

namespace big
{
	enum rgb_controller_t
	{
		rgb_controller_green_up,
		rgb_controller_red_down,
		rgb_controller_blue_up,
		rgb_controller_green_down,
		rgb_controller_red_up,
		rgb_controller_blue_down,
	};

	void looped::session_rainbowtraffic() {

		static int rgb_controller_v = rgb_controller_green_up;

		static int red = 255;
		static int green = 0;
		static int blue = 0;

		if (g->vehicle.rainbow_paint.type != RainbowPaintType::Off)
		{
			int delay_step = 100;

			if (g->vehicle.rainbow_paint.type == RainbowPaintType::Spasm)
			{
				red = rand() % 256;
				green = rand() % 256;
				blue = rand() % 256;
			}
			else if (g->vehicle.rainbow_paint.type == RainbowPaintType::Fade)
			{
				delay_step = 10;

				switch (rgb_controller_v)
				{
				case rgb_controller_green_up:
					green += 5;
					if (green >= 255)
					{
						green = 255;
						rgb_controller_v = rgb_controller_red_down;
					}
					break;

				case rgb_controller_red_down:
					red -= 5;
					if (red < 0)
					{
						red = 0;
						rgb_controller_v = rgb_controller_blue_up;
					}
					break;

				case rgb_controller_blue_up:
					blue += 5;
					if (blue >= 255)
					{
						blue = 255;
						rgb_controller_v = rgb_controller_green_down;
					}
					break;

				case rgb_controller_green_down:
					green -= 5;
					if (green < 0)
					{
						green = 0;
						rgb_controller_v = rgb_controller_red_up;
					}
					break;

				case rgb_controller_red_up:
					red += 5;
					if (red >= 255)
					{
						red = 255;
						rgb_controller_v = rgb_controller_blue_down;
					}
					break;

				case rgb_controller_blue_down:
					blue -= 5;
					if (blue < 0)
					{
						blue = 0;
						rgb_controller_v = rgb_controller_green_up;
					}
					break;

				default:
					break;
				}
			}
			const int ElementAmount = 10;
			const int ArrSize = ElementAmount * 2 + 2;
			if (g->session.rainbowtraffic) {
				Vehicle* vehs = new Vehicle[ArrSize];
				vehs[0] = ElementAmount;
				int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

				for (int i = 0; i < VehFound; i++)
				{
					int OffsetID = i * 2 + 2;
					if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true))
					{
						if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(vehs[OffsetID]))
						{
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehs[OffsetID], red, green, blue);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehs[OffsetID], red, green, blue);
							VEHICLE::SET_VEHICLE_NEON_ENABLED(vehs[OffsetID], 0, 1);
							VEHICLE::SET_VEHICLE_NEON_ENABLED(vehs[OffsetID], 1, 1);
							VEHICLE::SET_VEHICLE_NEON_ENABLED(vehs[OffsetID], 2, 1);
							VEHICLE::SET_VEHICLE_NEON_ENABLED(vehs[OffsetID], 3, 1);
							VEHICLE::SET_VEHICLE_NEON_COLOUR(vehs[OffsetID], red, green, blue);
						}
					}
				}
			}

		}
	}
}