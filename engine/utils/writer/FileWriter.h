//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_FILEWRITER_H
#define FLASH_FILEWRITER_H

#include "Writer.h"

namespace WriterUtil {

    class FileWriter : public Writer {
    public:
        explicit FileWriter(const std::string &filename);

        bool write(const char *message, const std::ios::openmode &mode) const override;

        bool write(const std::string &message, const std::ios::openmode &mode) const override;

    protected:
        std::string m_filename;
    };

}
#endif //FLASH_FILEWRITER_H
