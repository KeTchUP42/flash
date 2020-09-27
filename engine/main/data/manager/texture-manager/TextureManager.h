//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_TEXTUREMANAGER_H
#define FLASH_TEXTUREMANAGER_H

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

namespace Managers {

    /**
     * @brief The base class of the TextureManager class hierarchy.
     * @namespace Managers
     *
     * This class defines base TextureManager interface.
     */
    class TextureManager {
    public:
        explicit TextureManager(const std::string &textureDirectory)
                : TEXTURES_DIRECTORY(textureDirectory) {}

        explicit TextureManager(const char *textureDirectory)
                : TEXTURES_DIRECTORY(textureDirectory) {}

        /**
         * @brief Method loads texture from Texture directory.
         * @param filename Texture file name in Texture directory.
         * @param area Area of the texture to loadTexture.
         * @return New Texture.
         */
        std::shared_ptr<sf::Texture> loadTexture(const std::string &filename, const sf::Rect<int> &area = sf::IntRect()) const;

        /**
         * @brief Method loads image from file.
         * @param filename Image file name.
         * @return New Image.
         */
        std::shared_ptr<sf::Image> loadImage(const std::string &filename) const;

        virtual ~TextureManager() = default;

    protected:
        const std::string TEXTURES_DIRECTORY;
    };
}

#endif //FLASH_TEXTUREMANAGER_H
