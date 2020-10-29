//
// Created by roman on 27.09.2020.
//
#include "FontManager.h"
#include "../../../support/exceptions/custom/FontCannotBeLoaded.h"

std::shared_ptr<sf::Font> Managers::FontManager::loadFont(const std::string &filename) const {
    std::shared_ptr<sf::Font> font(new sf::Font());

    if (!font->loadFromFile(FONTS_DIRECTORY + "/" + filename))
        throw PreferredExceptions::FontCannotBeLoaded("Font " + filename + " cannot be loaded.");

    return font;
}