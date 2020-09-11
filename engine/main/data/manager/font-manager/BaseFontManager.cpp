//
// Created by roman on 24.08.2020.
//

#include "BaseFontManager.h"
#include "../../../general/exceptions/custom/FontCanNotBeLoaded.h"

std::shared_ptr<sf::Font> Managers::BaseFontManager::loadFont(const std::string &filename) const {
    std::shared_ptr<sf::Font> font(new sf::Font());

    if (!font->loadFromFile(_fonts + "/" + filename))
        throw PreferredExceptions::FontCanNotBeLoaded("Font " + filename + " cannot be loaded.");

    return std::move(font);
}
