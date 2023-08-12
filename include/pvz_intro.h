#ifndef PVZ_INTRO_H
#define PVZ_INTRO_H

#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "pvz_scene.h"
#include "pvz_scene_type.h"
#include "pvz_intro_background.h"

namespace bn {
    class sprite_text_generator;
}

namespace pvz {
    class butano_background;

    class intro : public scene {
        public:
            intro(bn::sprite_text_generator& text_generator, intro_background& intro_background);

            [[nodiscard]] bn::optional<pvz::scene_type> update() final;

        private:
            bn::vector<bn::sprite_ptr, 20> _text_sprites;
            int _counter = 60*4;
    };
}




#endif