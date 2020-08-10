//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_WRITER_H
#define FLASH_WRITER_H

#include <string>
#include <iostream>

namespace WriterUtil {

    class Writer {
    public:
        Writer() = default;

        Writer &operator=(const Writer &) = delete;

        /**
         * Writer main method wich writes std::string to file or files
         */
        virtual bool write(const std::string &, const std::ios::openmode &mode = std::ios::app) const noexcept = 0;

        /**
         * Writer main method wich writes 'C' string to file or files
         */
        virtual bool write(const char *, const std::ios::openmode &mode = std::ios::app) const noexcept = 0;

        virtual ~Writer() noexcept = default;
    };

}
#endif //FLASH_WRITER_H
