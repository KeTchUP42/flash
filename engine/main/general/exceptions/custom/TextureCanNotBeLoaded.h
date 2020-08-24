//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_TEXTURECANNOTBELOADED_H
#define FLASH_TEXTURECANNOTBELOADED_H

#include "../RuntimeException.h"

namespace PreferredExceptions {
    class TextureCanNotBeLoaded : public RuntimeException {
    public:
        explicit TextureCanNotBeLoaded(const char *message)
                : RuntimeException(message) {}

        explicit TextureCanNotBeLoaded(const std::string &message)
                : RuntimeException(message) {}
    };
}

#endif //FLASH_TEXTURECANNOTBELOADED_H
