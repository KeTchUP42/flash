//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_WRITER_H
#define FLASH_WRITER_H

#include <string>
#include <iostream>

namespace WriterUtil {

    /**
     * @brief The base class of the Writer class hierarchy.
     * @namespace WriterUtil
     *
     * This class defines base Writer interface and fields.
    */
    class Writer {
    public:
        Writer() = default;

        Writer &operator=(const Writer &) = delete;

        /**
         * Writer main method which writes std::string to stream.
         */
        virtual bool write(const std::string &__s, const std::ios::openmode &mode = std::ios::app) const noexcept = 0;

        /**
         * Writer main method which writes 'C' string to stream.
         */
        virtual bool write(const char *__s, const std::ios::openmode &mode = std::ios::app) const noexcept = 0;

        virtual ~Writer() noexcept = default;
    };

}
#endif //FLASH_WRITER_H
