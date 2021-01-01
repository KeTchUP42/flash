//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_AUDIOFILECANNOTBEOPENED_H
#define FLASH_AUDIOFILECANNOTBEOPENED_H

#include "../RuntimeException.h"

namespace Exceptions {

    class AudioFileCannotBeOpened : public RuntimeException {
    public:
        explicit AudioFileCannotBeOpened(const char *message) : RuntimeException(message) {}

        explicit AudioFileCannotBeOpened(const std::string &message) : RuntimeException(message) {}
    };
}

#endif //FLASH_AUDIOFILECANNOTBEOPENED_H
