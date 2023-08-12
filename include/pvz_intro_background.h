#ifndef PVZ_INTRO_BACKGROUND_H
#define PVZ_INTRO_BACKGROUND_H

#include "bn_regular_bg_ptr.h"

namespace bn {
    class regular_bg_ptr;
}

namespace pvz {
    class intro_background {
        public:
            intro_background() {
                _set_visible();
            }

            void put_under_all();

            void update();

        private:
            bn::optional<bn::regular_bg_ptr> bg;

            void _set_visible();
    };
}

#endif