//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_FILEWRITER_H
#define FLASH_FILEWRITER_H

#include "Writer.h"

namespace WriterUtil {

    class FileWriter : public Writer {
    public:
        explicit FileWriter(const std::string &filepath);

        explicit FileWriter(const char *filepath);

        bool write(const char *message, const std::ios::openmode &mode = std::ios::app) const noexcept override;

        bool write(const std::string &message, const std::ios::openmode &mode = std::ios::app) const noexcept override;

    protected:
        void checkPath() const;

    protected:
        const std::string _path;
    };

}
#endif //FLASH_FILEWRITER_H
