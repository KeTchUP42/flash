//
// Created by roman on 05.08.2020.
//

#ifndef FLASH_FORMATTER_H
#define FLASH_FORMATTER_H

#include <string>

namespace LoggerUtil {

    template<typename DataType = std::string>
    class Formatter {
    public:
        Formatter() = default;

        Formatter<DataType> &operator=(const Formatter<DataType> &) = delete;

        virtual DataType format(const DataType &) const noexcept = 0;

        virtual ~Formatter() = default;
    };
}
#endif //FLASH_FORMATTER_H
