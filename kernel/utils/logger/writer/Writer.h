//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_WRITER_H
#define FLASH_WRITER_H

#include <string>

namespace LoggerUtil {

    class Writer {
    public:
        Writer() = default;

        virtual bool write(const std::string &) const noexcept = 0;

        virtual bool write(const char *) const noexcept = 0;

        virtual ~Writer() = default;
    };

}
#endif //FLASH_WRITER_H
