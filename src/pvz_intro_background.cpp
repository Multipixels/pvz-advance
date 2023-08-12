#include "pvz_intro_background.h"

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_items_butano_background.h"

namespace pvz {

    void intro_background::put_under_all() {
        _set_visible();
        
        bg -> set_priority(3);
    }

    void intro_background::update() {

    }

    void intro_background::_set_visible() {
        bg = bn::regular_bg_items::butano_background.create_bg(0, 0);
    }
}