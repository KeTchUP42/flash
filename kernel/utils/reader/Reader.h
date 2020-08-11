//
// Created by roman on 10.08.2020.
//

#ifndef FLASH_READER_H
#define FLASH_READER_H

#include <string>
#include <vector>

namespace ReaderUtil {

    /**
     *  @brief  The base class of the Reader class hierarchy.
     *  @namespace ReaderUtil
     *
     *  This class defines base Reader interface and fields.
    */
    class Reader {
    public:
        Reader() = default;

        Reader &operator=(const Reader &) = delete;

        /**
         * Reader method which returns std::string from stream.
         */
        virtual std::string read() const noexcept = 0;

        /**
         * Reader method which returns a std::vector<std::string> of lines from stream.
          */
        virtual std::vector<std::string> readlines() const noexcept = 0;

        virtual ~Reader() noexcept = default;
    };
}

#endif //FLASH_READER_H
