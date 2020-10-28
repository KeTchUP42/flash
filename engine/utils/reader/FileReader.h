//
// Created by roman on 10.08.2020.
//

#ifndef FLASH_FILEREADER_H
#define FLASH_FILEREADER_H

#include "Reader.h"

namespace ReaderUtil {

    class FileReader : public Reader {
    public:
        FileReader(const std::string &filepath);

        std::string read() const override;

        std::vector<std::string> readlines() const override;

    protected:
        std::string m_filepath;
    };
}

#endif //FLASH_FILEREADER_H
