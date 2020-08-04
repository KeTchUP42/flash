//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_FILEWRITER_H
#define FLASH_FILEWRITER_H


#include "../../../main/general/exceptions/KernelRuntimeException.h"
#include "Writer.h"

namespace LoggerUtil {

    class FileWriter : public Writer {
    public:

        class FileIsNotOpen : public KernelExceptions::KernelRuntimeException {
        public:
            explicit FileIsNotOpen(const char *message) : KernelRuntimeException(message) {}
        };

        explicit FileWriter(const std::string &filepath);

        explicit FileWriter(const char *filepath);

        bool write(const char *) const noexcept override;

        bool write(const std::string &) const noexcept override;

        ~FileWriter() override;

    protected:
        void checkFile() const;

        const char *_path;
    };

}
#endif //FLASH_FILEWRITER_H
