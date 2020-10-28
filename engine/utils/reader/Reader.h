//
// Created by roman on 10.08.2020.
//

#ifndef FLASH_READER_H
#define FLASH_READER_H

#include <string>
#include <vector>

namespace ReaderUtil {

    /**
     * @brief The class is a functional interface for the Reader.
     * @namespace ReaderUtil
     *
     * This class defines base Reader interface.
    */
    class Reader {
    public:
        Reader() = default;

        /**
         * @brief Method reads data from stream.
         * @return Line from stream.
         */
        virtual std::string read() const = 0;

        /**
         * @brief Method reads data from stream.
         * @return Lines from stream.
         */
        virtual std::vector<std::string> readlines() const = 0;

        virtual ~Reader() noexcept = default;
    };
}

#endif //FLASH_READER_H
