//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_BASICTEXTUREMANAGER_H
#define FLASH_BASICTEXTUREMANAGER_H

#include "TextureManager.h"

namespace Managers {

    class BasicTextureManager : public TextureManager {
    public:
        explicit BasicTextureManager(const std::string &textureDirectory)
                : TextureManager(textureDirectory) {}

        explicit BasicTextureManager(const char *textureDirectory)
                : TextureManager(textureDirectory) {}

        std::shared_ptr<sf::Texture>
        loadTexture(const std::string &filename, const sf::Rect<int> &area = sf::IntRect()) const override;

        std::shared_ptr<sf::Image> loadImage(const std::string &filename) const override;
    };
}

#endif //FLASH_BASICTEXTUREMANAGER_H
