//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_BASEFONTMANAGER_H
#define FLASH_BASEFONTMANAGER_H

#include "FontManager.h"

namespace Managers {

    class BaseFontManager : public FontManager {
    public:
        explicit BaseFontManager(const std::string &fontDirectory)
                : FontManager(fontDirectory) {}

        explicit BaseFontManager(const char *fontDirectory)
                : FontManager(fontDirectory) {}

        std::shared_ptr<sf::Font> load(const std::string &filename) const override;
    };
}

#endif //FLASH_BASEFONTMANAGER_H
