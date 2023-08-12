#ifndef BF_STATUS_H
#define BF_STATUS_H

namespace pvz {
    class status {
        public:
            status();

            [[nodiscard]] int level() const {
                return _level;
            }

            [[nodiscard]] bool add_level();

        private:
            int _level = 1;
    };
}

#endif