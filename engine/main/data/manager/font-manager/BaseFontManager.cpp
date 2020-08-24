//
// Created by roman on 24.08.2020.
//

#include "BaseFontManager.h"
#include "../../../general/exceptions/custom/FontCanNotBeLoaded.h"

std::shared_ptr<sf::Font> DataManagers::BaseFontManager::load(const std::string &filename) const {
    std::shared_ptr<sf::Font> font(new sf::Font());

    if (!font->loadFromFile(_fontDirectory + "/" + filename))
        throw PreferredExceptions::FontCanNotBeLoaded(filename.c_str());

    return std::move(font);
}
