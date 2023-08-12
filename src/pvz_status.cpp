#include "pvz_status.h"

#include "bn_sram.h"
#include "bn_sstream.h"
#include "bn_string_view.h"

namespace pvz {
    namespace {
        struct sram_data {
            constexpr static const char* valid_label = "pvz001";

            char label[8] = {};
            int level = 1;

            [[nodiscard]] bool read() {
                bn::sram::read(*this);
                return bn::string_view(label) == valid_label;
            }

            void write() {
                bn::istring_base label_istring(label);
                bn::ostringstream label_stream(label_istring);
                label_stream.append(valid_label);
                bn::sram::write(*this);
            }
        };
    }

    bool status::add_level() {
        if(_level != 50) {
            _level++;
        } else {
            _level = 1;
        }

        return true;
    }
}