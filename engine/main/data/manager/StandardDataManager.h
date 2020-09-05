//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_STANDARDDATAMANAGER_H
#define FLASH_STANDARDDATAMANAGER_H

#include "DataManager.h"

namespace Managers {

    class StandardDataManager : public DataManager {
    public:
        explicit StandardDataManager(AudioManager *audioManager, ConfigManager *configManager,
                                     FontManager *fontManager, LogManager *logManager, TextureManager *textureManager)
                : _audioManager(audioManager), _configManager(configManager), _fontManager(fontManager),
                  _logManager(logManager), _textureManager(textureManager) {}

        explicit StandardDataManager(const std::shared_ptr<AudioManager> &audioManager,
                                     const std::shared_ptr<ConfigManager> &configManager,
                                     const std::shared_ptr<FontManager> &fontManager,
                                     const std::shared_ptr<LogManager> &logManager,
                                     const std::shared_ptr<TextureManager> &textureManager)
                : _audioManager(audioManager), _configManager(configManager), _fontManager(fontManager),
                  _logManager(logManager), _textureManager(textureManager) {}

        std::shared_ptr<AudioManager> getAudioManager() const noexcept override;

        std::shared_ptr<FontManager> getFontManager() const noexcept override;

        std::shared_ptr<LogManager> getLogManager() const noexcept override;

        std::shared_ptr<TextureManager> getTextureManager() const noexcept override;

        std::shared_ptr<ConfigManager> getConfigManager() const noexcept override;

    private:
        std::shared_ptr<AudioManager> _audioManager;
        std::shared_ptr<ConfigManager> _configManager;
        std::shared_ptr<FontManager> _fontManager;
        std::shared_ptr<LogManager> _logManager;
        std::shared_ptr<TextureManager> _textureManager;
    };
}

#endif //FLASH_STANDARDDATAMANAGER_H
