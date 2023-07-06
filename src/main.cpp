#include "bn_core.h"
#include "bn_sprite_text_generator.h" // Font generator
#include "bn_regular_bg_ptr.h"

#include "pvz_big_sprite_font.h"
#include "bn_regular_bg_items_bg.h"

int main()
{
    bn::core::init();

    // Creates big text generator
    bn::sprite_text_generator big_text_generator(pvz::big_sprite_font);

    bn::regular_bg_ptr bg = bn::regular_bg_items::bg.create_bg(0, 0);

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
