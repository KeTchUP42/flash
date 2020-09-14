//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_BASICFONTMANAGER_H
#define FLASH_BASICFONTMANAGER_H

#include "FontManager.h"

namespace Managers {

    class BasicFontManager : public FontManager {
    public:
        explicit BasicFontManager(const std::string &fontDirectory)
                : FontManager(fontDirectory) {}

        explicit BasicFontManager(const char *fontDirectory)
                : FontManager(fontDirectory) {}

        std::shared_ptr<sf::Font> loadFont(const std::string &filename) const override;
    };
}

#endif //FLASH_BASICFONTMANAGER_H
