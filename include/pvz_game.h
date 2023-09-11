#ifndef PVZ_GAME_H
#define PVZ_GAME_H

#include "bn_sprite_ptr.h"
#include "pvz_scene.h"
#include "pvz_scene_type.h"
#include "pvz_day_yard_background.h"

namespace bn {
    class sprite_text_generator;
}

namespace pvz {
    class day_yard_background;

    class game : public scene {
        game(bn::sprite_text_generator& text_generator, intro_background& intro_background);

            [[nodiscard]] bn::optional<pvz::scene_type> update() final;

        private:
            bn::vector<bn::sprite_ptr, 20> _text_sprites;
    };
}





#endif