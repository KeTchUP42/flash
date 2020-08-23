//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_AUDIOFILECANNOTBEOPENED_H
#define FLASH_AUDIOFILECANNOTBEOPENED_H

#include "../RuntimeException.h"

namespace PreferredExceptions {
    class AudioFileCanNotBeOpened : public RuntimeException {
    public:
        explicit AudioFileCanNotBeOpened(const char *message)
                : RuntimeException(message) {}

        explicit AudioFileCanNotBeOpened(const std::string &message)
                : RuntimeException(message) {}
    };
}

#endif //FLASH_AUDIOFILECANNOTBEOPENED_H
