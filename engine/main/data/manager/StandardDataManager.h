//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_STANDARDDATAMANAGER_H
#define FLASH_STANDARDDATAMANAGER_H

#include "DataManager.h"

namespace DataManagers {

    class StandardDataManager : public DataManager {
    public:

        explicit StandardDataManager(AudioManager *audioManager, FontManager *fontManager,
                                     LogManager *logManager, TextureManager *textureManager) :
                _audioManager(audioManager), _fontManager(fontManager),
                _logManager(logManager), _textureManager(textureManager) {}

        explicit StandardDataManager(std::shared_ptr<AudioManager> audioManager, std::shared_ptr<FontManager> fontManager,
                                     std::shared_ptr<LogManager> logManager, std::shared_ptr<TextureManager> textureManager) :
                _audioManager(audioManager), _fontManager(fontManager),
                _logManager(logManager), _textureManager(textureManager) {}

        std::shared_ptr<AudioManager> getAudioManager() const noexcept override;

        std::shared_ptr<FontManager> getFontManager() const noexcept override;

        std::shared_ptr<LogManager> getLogManager() const noexcept override;

        std::shared_ptr<TextureManager> getTextureManager() const noexcept override;

    private:
        std::shared_ptr<AudioManager> _audioManager;
        std::shared_ptr<FontManager> _fontManager;
        std::shared_ptr<LogManager> _logManager;
        std::shared_ptr<TextureManager> _textureManager;
    };
}

#endif //FLASH_STANDARDDATAMANAGER_H
