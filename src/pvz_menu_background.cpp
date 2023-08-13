#include "pvz_menu_background.h"

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_items_menu_background.h"

namespace pvz {

    void menu_background::put_under_all() {
        _set_visible();
        
        bg -> set_priority(3);
    }

    void menu_background::update() {

    }

    void menu_background::_set_visible() {
        bg = bn::regular_bg_items::menu_background.create_bg(0, 0);
    }
}