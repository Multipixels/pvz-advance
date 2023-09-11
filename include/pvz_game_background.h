#ifndef PVZ_GAME_BACKGROUND_H
#define PVZ_GAME_BACKGROUND_H

#include "bn_camera_ptr.h"

namespace pvz::game {
    class stage;

    class background {
        public:
            background(const stage& stage, const bn::camera_ptr& camera);
    
            background(const background& other) = delete;

            background &operator=(const background& other) = delete;

            void set_visible(bool visible);

            void reset();

            void update();
    };
}

#endif