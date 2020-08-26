//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_FONTMANAGER_H
#define FLASH_FONTMANAGER_H

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

namespace DataManagers {

    /**
     * @brief The base class of the FontManager class hierarchy.
     * @namespace DataManagers
     *
     * This class defines base FontManager interface and fields.
     */
    class FontManager {
    public:
        explicit FontManager(const std::string &fontDirectory)
                : _fontDirectory(fontDirectory) {}

        explicit FontManager(const char *fontDirectory)
                : _fontDirectory(fontDirectory) {}

        /**
         * @brief Method loads font from Font directory.
         * @param filename Font file name in Font directory.
         * @return std::shared_ptr<sf::Font>
         */
        virtual std::shared_ptr<sf::Font> load(const std::string &filename) const = 0;

        virtual ~FontManager() = default;

    protected:
        const std::string _fontDirectory;
    };
}

#endif //FLASH_FONTMANAGER_H
