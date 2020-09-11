//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_FONTMANAGER_H
#define FLASH_FONTMANAGER_H

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

namespace Managers {

    /**
     * @brief The base class of the FontManager class hierarchy.
     * @namespace Managers
     *
     * This class defines base FontManager interface and fields.
     */
    class FontManager {
    public:
        explicit FontManager(const std::string &fontDirectory)
                : _fonts(fontDirectory) {}

        explicit FontManager(const char *fontDirectory)
                : _fonts(fontDirectory) {}

        /**
         * @brief Method loads font from Font directory.
         * @param filename Font file name in Font directory.
         * @return New Font.
         */
        virtual std::shared_ptr<sf::Font> loadFont(const std::string &filename) const = 0;

        virtual ~FontManager() = default;

    protected:
        const std::string _fonts;
    };
}

#endif //FLASH_FONTMANAGER_H
