//
// Created by roman on 07.08.2020.
//

#ifndef FLASH_FILECANNOTBEOPENED_H
#define FLASH_FILECANNOTBEOPENED_H

#include "../RuntimeException.h"

namespace PreferredExceptions {

    class FileCanNotBeOpened : public RuntimeException {
    public:
        explicit FileCanNotBeOpened(const char *message)
                : RuntimeException(message) {}

        explicit FileCanNotBeOpened(const std::string &message)
                : RuntimeException(message) {}
    };
}
#endif //FLASH_FILECANNOTBEOPENED_H
