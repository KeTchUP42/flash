//
// Created by roman on 24.08.2020.
//

#include "StandardDataManager.h"

std::shared_ptr<Managers::AudioManager> Managers::StandardDataManager::getAudioManager() const noexcept {
    return _audioManager;
}

std::shared_ptr<Managers::ConfigManager> Managers::StandardDataManager::getConfigManager() const noexcept {
    return _configManager;
}

std::shared_ptr<Managers::FontManager> Managers::StandardDataManager::getFontManager() const noexcept {
    return _fontManager;
}

std::shared_ptr<Managers::LogManager> Managers::StandardDataManager::getLogManager() const noexcept {
    return _logManager;
}

std::shared_ptr<Managers::TextureManager> Managers::StandardDataManager::getTextureManager() const noexcept {
    return _textureManager;
}