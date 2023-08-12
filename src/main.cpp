#include "bn_core.h"
#include "bn_sprite_text_generator.h" // Font generator
#include "bn_unique_ptr.h"

#include "pvz_intro.h"
#include "pvz_game.h"
#include "pvz_status.h"
#include "pvz_intro_background.h"
#include "pvz_big_sprite_font.h"

// #include "bn_regular_bg_ptr.h"
// #include "bn_sprite_ptr.h"

// #include "bn_regular_bg_items_bg.h"
// #include "bn_regular_bg_items_front_yard.h"

// #include "bn_sprite_items_plant_peashooter.h"
// #include "bn_sprite_items_plant_sunflower.h"
// #include "bn_sprite_items_plant_cherry_bomb.h"
// #include "bn_sprite_items_plant_wallnut.h"
// #include "bn_sprite_items_plant_wallnut2.h"
// #include "bn_sprite_items_plant_wallnut3.h"
// #include "bn_sprite_items_plant_wallnut4.h"

int main() {
    bn::core::init();

    // Creates big text generator
    bn::sprite_text_generator big_text_generator(pvz::big_sprite_font);
    big_text_generator.set_bg_priority(1);

    //pvz::status status;
    pvz::intro_background intro_background;
    bn::unique_ptr<pvz::scene> scene(new pvz::intro(big_text_generator, intro_background));
    bn::optional<pvz::scene_type> next_scene = pvz::scene_type::INTRO;
    int wait_frames = 0;

    while(true) {
        if(scene) {
            next_scene = scene->update();
        }

        intro_background.update();
        bn::core::update();

        if(next_scene) {
            if(scene) {
                scene.reset();
                wait_frames = 30;
            }

            --wait_frames;

            if(!wait_frames) {
                switch(*next_scene) {
                    case pvz::scene_type::INTRO:
                        scene.reset(new pvz::intro(big_text_generator, intro_background));
                        break;
                    default:
                        BN_ERROR("Invalid next scene: ", int(*next_scene));
                        break;
                }
            }
        }
    }
}




/*
int main()
{
    bn::core::init();

    // Creates big text generator
    bn::sprite_text_generator big_text_generator(pvz::big_sprite_font);

    // bn::sprite_ptr peashooter = bn::sprite_items::plant_peashooter.create_sprite(0, 0);
    // bn::sprite_ptr sunflower = bn::sprite_items::plant_sunflower.create_sprite(0, 16);
    // bn::sprite_ptr cherry = bn::sprite_items::plant_cherry_bomb.create_sprite(0, 32);
    // bn::sprite_ptr wallnut = bn::sprite_items::plant_wallnut.create_sprite(0, 48);
    // bn::sprite_ptr wallnut1 = bn::sprite_items::plant_wallnut2.create_sprite(0, -16);
    // bn::sprite_ptr wallnut2 = bn::sprite_items::plant_wallnut3.create_sprite(0, -32);
    // bn::sprite_ptr wallnut3 = bn::sprite_items::plant_wallnut4.create_sprite(0, -48);

    bn::regular_bg_ptr bg = bn::regular_bg_items::front_yard.create_bg(0, 0); 

    // bn::vector<bn::sprite_ptr, 32> text_sprites;
    // big_text_generator.generate(-85, -60, "THE QUICK BROWN FOX JUMPS", text_sprites);
    // big_text_generator.generate(-55, -44, "OVER THE LAZY DOG", text_sprites);

    // big_text_generator.generate(-72, -24, "the quick brown fox jumps", text_sprites);
    // big_text_generator.generate(-42, -8, "over the lazy dog", text_sprites);

    // big_text_generator.generate(-72, 16, "A HUGE WAVE OF ZOMBIES", text_sprites);
    // big_text_generator.generate(-42, 32, "IS APPROACHING", text_sprites);
    
    // big_text_generator.generate(-30, 48, "0123456789", text_sprites);

    while(true)
    {
        bn::core::update();
    }
}
*/