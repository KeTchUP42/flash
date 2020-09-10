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
                : _textures(textureDirectory) {}

        explicit TextureManager(const char *textureDirectory)
                : _textures(textureDirectory) {}

        /**
         * @brief Method loads texture from Texture directory.
         * @param filename Texture file name in Texture directory.
         * @param area Area of the texture to load.
         * @return std::shared_ptr<sf::Texture>
         */
        virtual std::shared_ptr<sf::Texture>
        load(const std::string &filename, const sf::Rect<int> &area = sf::IntRect()) const = 0;

        virtual ~TextureManager() = default;

    protected:
        const std::string _textures;
    };
}

#endif //FLASH_TEXTUREMANAGER_H
