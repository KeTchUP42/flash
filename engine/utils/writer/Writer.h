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
         * @brief Method writes data to the stream.
         * @param __s Input stream data.
         * @param mode Stream open mode.
         * @return Was success?
         */
        virtual bool write(const std::string &__s, const std::ios::openmode &mode) const = 0;

        /**
         * @brief Method writes data to the stream.
         * @param __s Input stream data.
         * @param mode Stream open mode.
         * @return Was success?
         */
        virtual bool write(const char *__s, const std::ios::openmode &mode) const = 0;

        virtual ~Writer() = default;
    };
}
#endif //FLASH_WRITER_H
