//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_FILEWRITER_H
#define FLASH_FILEWRITER_H

#include "Writer.h"
#include "../../../main/general/exceptions/KernelRuntimeException.h"

namespace LoggerUtil {

    class FileWriter : public Writer {
    public:

        class FileCanNotBeOpened : public KernelExceptions::KernelRuntimeException {
        public:
            explicit FileCanNotBeOpened(const char *message) : KernelRuntimeException(message) {}
        };

        explicit FileWriter(const std::string &filepath);

        explicit FileWriter(const char *filepath);

        bool write(const char *message) const noexcept override;

        bool write(const std::string &message) const noexcept override;

    protected:
        void checkPath() const;

        const std::string _path;
    };

}
#endif //FLASH_FILEWRITER_H
