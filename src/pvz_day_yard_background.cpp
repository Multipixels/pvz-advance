#include "pvz_day_yard_background.h"

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_items_intro_background.h"

namespace pvz {

    void day_yard__background::put_under_all() {
        _set_visible();
        
        bg -> set_priority(3);
    }

    void day_yard_background::update() {

    }

    void day_yard_background::_set_visible() {
        bg = bn::regular_bg_items::day_yard_background.create_bg(0, 0);
    }
}