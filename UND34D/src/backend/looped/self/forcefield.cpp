#include "backend/looped/looped.hpp"
#include "natives.hpp"
#include "util/entity.hpp"
#include "services/players/player_service.hpp"

namespace big
{
    void looped::self_force_field()
    {
        if (g->self.force_field)
        {
            Entity Ped = self::ped;
            Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Ped, 0);
            FIRE::ADD_EXPLOSION(pCoords.x, pCoords.y, pCoords.z, 7, 9.0f, false, true, 0.0f, true);
            FIRE::ADD_EXPLOSION(pCoords.x + 10.f, pCoords.y + 10.f, pCoords.z + 10.f, 7, 960.0f, false, true, 0.0f, true);
            FIRE::ADD_EXPLOSION(pCoords.x + 20.f, pCoords.y + 20.f, pCoords.z + 20.f, 7, 960.0f, false, true, 0.0f, true);
            FIRE::ADD_EXPLOSION(pCoords.x + 30.f, pCoords.y + 30.f, pCoords.z + 30.f, 7, 960.0f, false, true, 0.0f, true);
            FIRE::ADD_EXPLOSION(pCoords.x + 40.f, pCoords.y + 40.f, pCoords.z + 40.f, 7, 960.0f, false, true, 0.0f, true);
            FIRE::ADD_EXPLOSION(pCoords.x + 50.f, pCoords.y + 50.f, pCoords.z + 50.f, 7, 960.0f, false, true, 0.0f, true);
        }
    }
}