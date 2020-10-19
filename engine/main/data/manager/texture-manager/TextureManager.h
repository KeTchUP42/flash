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
     * @brief The class provides easy access to visual data such as textures and images.
     * @namespace Managers
     *
     * This class defines TextureManager interface and realization.
     */
    class TextureManager {
    public:
        explicit TextureManager(const std::string &textureDirectory)
                : TEXTURES_DIRECTORY(textureDirectory) {}

        explicit TextureManager(const char *textureDirectory)
                : TEXTURES_DIRECTORY(textureDirectory) {}

        /**
         * @brief Method loads texture from texture directory.
         * @param filename Texture file name in texture directory.
         * @param area Area of the texture.
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

    private:
        const std::string TEXTURES_DIRECTORY;
    };
}

#endif //FLASH_TEXTUREMANAGER_H
