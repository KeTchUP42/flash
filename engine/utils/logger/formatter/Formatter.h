//
// Created by roman on 05.08.2020.
//

#ifndef FLASH_FORMATTER_H
#define FLASH_FORMATTER_H

#include <string>

namespace LoggerUtil {

    /**
    * @brief The interface of the Formatter strategy class hierarchy. Uses in Logger hierarchy.
    * @namespace LoggerUtil
    *
    * This class defines base interface of Formatter classes.
    */
    template<typename T = std::string>
    class Formatter {
    public:
        Formatter() = default;

        /**
         * Main formatter template handle method.
         * Uses to generate output line which logger writes to the stream.
         *
         * @param T const type ref.
         * @return T type
         */
        virtual T format(const T &) const noexcept = 0;

        virtual ~Formatter() = default;
    };
}
#endif //FLASH_FORMATTER_H
