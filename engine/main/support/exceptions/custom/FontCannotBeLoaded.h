//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_FONTCANNOTBELOADED_H
#define FLASH_FONTCANNOTBELOADED_H

#include "../RuntimeException.h"

namespace Exceptions {

    class FontCannotBeLoaded : public RuntimeException {
    public:
        explicit FontCannotBeLoaded(const char *message)
                : RuntimeException(message) {}

        explicit FontCannotBeLoaded(const std::string &message)
                : RuntimeException(message) {}
    };
}

#endif //FLASH_FONTCANNOTBELOADED_H
