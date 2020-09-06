//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_BASETEXTUREMANAGER_H
#define FLASH_BASETEXTUREMANAGER_H

#include "TextureManager.h"

namespace Managers {

    class BaseTextureManager : public TextureManager {
    public:
        explicit BaseTextureManager(const std::string &textureDirectory)
                : TextureManager(textureDirectory) {}

        explicit BaseTextureManager(const char *textureDirectory)
                : TextureManager(textureDirectory) {}

        std::shared_ptr<sf::Texture> load(const std::string &filename, const sf::Rect<int> &area = sf::IntRect()) const override;
    };
}

#endif //FLASH_BASETEXTUREMANAGER_H
