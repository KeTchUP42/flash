//
// Created by roman on 07.08.2020.
//

#ifndef FLASH_FILECANNOTBEOPENED_H
#define FLASH_FILECANNOTBEOPENED_H

#include "../RuntimeException.h"

namespace PreferredExceptions {

    class FileCannotBeOpened : public RuntimeException {
    public:
        explicit FileCannotBeOpened(const char *message)
                : RuntimeException(message) {}

        explicit FileCannotBeOpened(const std::string &message)
                : RuntimeException(message) {}
    };
}
#endif //FLASH_FILECANNOTBEOPENED_H
