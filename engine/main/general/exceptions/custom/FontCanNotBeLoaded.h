//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_FONTCANNOTBELOADED_H
#define FLASH_FONTCANNOTBELOADED_H

#include "../RuntimeException.h"

namespace PreferredExceptions {
    class FontCanNotBeLoaded : public RuntimeException {
    public:
        explicit FontCanNotBeLoaded(const char *message)
                : RuntimeException(message) {}

        explicit FontCanNotBeLoaded(const std::string &message)
                : RuntimeException(message) {}
    };
}

#endif //FLASH_FONTCANNOTBELOADED_H
