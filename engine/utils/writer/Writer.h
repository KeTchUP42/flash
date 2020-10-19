//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_WRITER_H
#define FLASH_WRITER_H

#include <string>
#include <iostream>

namespace WriterUtil {

    /**
     * @brief The class is a functional interface for the Writer.
     * @namespace WriterUtil
     *
     * This class defines base Writer interface.
    */
    class Writer {
    public:
        Writer() = default;

        /**
         * Writer main method which writes std::string to stream.
         */
        virtual bool write(const std::string &__s, const std::ios::openmode &mode) const noexcept = 0;

        /**
         * Writer main method which writes 'C' string to stream.
         */
        virtual bool write(const char *__s, const std::ios::openmode &mode) const noexcept = 0;

        virtual ~Writer() noexcept = default;
    };

}
#endif //FLASH_WRITER_H
