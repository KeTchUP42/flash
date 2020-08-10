//
// Created by roman on 10.08.2020.
//

#ifndef FLASH_FILEREADER_H
#define FLASH_FILEREADER_H

#include "Reader.h"

namespace IniParseUtil {

    class FileReader : public Reader {
    public:
        explicit FileReader(const std::string &filepath);

        explicit FileReader(const char *filepath);

        std::string read() const noexcept override;

        std::vector<std::string> readlines() const noexcept override;

    protected:
        void checkPath(const std::string &path) const;

        std::string _path;
    };
}

#endif //FLASH_FILEREADER_H
