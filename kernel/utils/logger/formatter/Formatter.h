//
// Created by roman on 05.08.2020.
//

#ifndef FLASH_FORMATTER_H
#define FLASH_FORMATTER_H

#include <string>

namespace LoggerUtil {

    template<typename T = std::string>
    class Formatter {
    public:
        Formatter() = default;

        Formatter<T> &operator=(const Formatter<T> &) = delete;

        virtual T format(const T &) const noexcept = 0;

        virtual ~Formatter() noexcept = default;
    };
}
#endif //FLASH_FORMATTER_H
