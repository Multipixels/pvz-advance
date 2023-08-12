#ifndef PVZ_SCENE_H
#define PVZ_SCENE_H

#include "bn_optional.h"

namespace pvz {
    enum class scene_type;

    class scene {
        public:
            virtual ~scene() = default;

            [[nodiscard]] virtual bn::optional<scene_type> update() = 0;

        protected:
            scene() = default;
    };
}

#endif