#ifndef PVZ_MENU_H
#define PVZ_MENU_H

#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "pvz_scene.h"
#include "pvz_scene_type.h"
#include "pvz_menu_background.h"

namespace bn {
    class sprite_text_generator;
}

namespace pvz {
    class menu_background;

    class menu : public scene {
        public:
            menu(bn::sprite_text_generator& text_generator, menu_background& menu_background);

            [[nodiscard]] bn::optional<pvz::scene_type> update() final;

        private:
            enum class state {
                START
            };

            state _state = state::START;
    };
}




#endif