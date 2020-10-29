//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_TEXTURECANNOTBELOADED_H
#define FLASH_TEXTURECANNOTBELOADED_H

#include "../RuntimeException.h"

namespace PreferredExceptions {

    class TextureCannotBeLoaded : public RuntimeException {
    public:
        explicit TextureCannotBeLoaded(const char *message)
                : RuntimeException(message) {}

        explicit TextureCannotBeLoaded(const std::string &message)
                : RuntimeException(message) {}
    };
}

#endif //FLASH_TEXTURECANNOTBELOADED_H
