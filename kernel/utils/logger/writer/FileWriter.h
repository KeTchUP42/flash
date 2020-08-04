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

        class FileIsNotOpen : public KernelExceptions::KernelRuntimeException {
        public:
            explicit FileIsNotOpen(const char *message) : KernelRuntimeException(message) {}
        };

        explicit FileWriter(const std::string &);

        bool write(const std::string &) const override;

        ~FileWriter() override;

    protected:
        std::ofstream *_out;
    };

}
#endif //FLASH_FILEWRITER_H
