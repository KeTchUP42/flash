//
// Created by roman on 24.08.2020.
//

#include "BasicFontManager.h"
#include "../../../other/exceptions/custom/FontCannotBeLoaded.h"

std::shared_ptr<sf::Font> Managers::BasicFontManager::loadFont(const std::string &filename) const {
    std::shared_ptr<sf::Font> font(new sf::Font());

    if (!font->loadFromFile(FONTS_DIRECTORY + "/" + filename))
        throw PreferredExceptions::FontCannotBeLoaded("Font " + filename + " cannot be loaded.");

    return std::move(font);
}
