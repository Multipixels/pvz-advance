#include "pvz_game.h"

#include "bn_string.h"
#include "bn_keypad.h"
#include "bn_sprite_text_generator.h"
#include "pvz_intro_background.h"
#include "pvz_scene_type.h"

namespace pvz {
    
    intro::intro(bn::sprite_text_generator& text_generator, intro_background& intro_background) {
        bn::string<32> middle_text("PRESS A TO START ");
        // middle_text.append(bn::to_string<4>(bn::version::major()));
        // middle_text.append('.');
        // middle_text.append(bn::to_string<4>(bn::version::minor()));
        // middle_text.append('.');
        // middle_text.append(bn::to_string<4>(bn::version::patch()));

        text_generator.set_center_alignment();
        text_generator.generate(0, -38, middle_text, _text_sprites);

        intro_background.put_under_all();
    }

    bn::optional<pvz::scene_type> intro::update() {
        bn::optional<pvz::scene_type> result;

        if (bn::keypad::a_pressed()) {
            result = pvz::scene_type::MENU;
            return result;
        }

        return result;
    }

}