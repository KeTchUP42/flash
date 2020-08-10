//
// Created by roman on 10.08.2020.
//

#ifndef FLASH_READER_H
#define FLASH_READER_H

#include <string>
#include <vector>

namespace IniParseUtil {

    class Reader {
    public:
        Reader() = default;

        Reader &operator=(const Reader &) = delete;

        /**
         * Reader method wich returns std::string from target file or ect.
         */
        virtual std::string read() const noexcept = 0;

        /**
         * Reader method wich returns a std::vector<std::string> of lines from targer file or ect.
          */
        virtual std::vector<std::string> readlines() const noexcept = 0;

        virtual ~Reader() noexcept = default;
    };
}

#endif //FLASH_READER_H
