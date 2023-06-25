#include "bn_core.h"
#include "bn_sprite_text_generator.h"

int main()
{
    bn::core::init();

    bn::sprite_text_generator small_text_generator(bf::small_sprite_font);
    

    while(true)
    {
        bn::core::update();
    }
}
