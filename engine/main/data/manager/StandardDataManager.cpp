//
// Created by roman on 24.08.2020.
//

#include "StandardDataManager.h"

std::shared_ptr<DataManagers::AudioManager> DataManagers::StandardDataManager::getAudioManager() const noexcept {
    return _audioManager;
}

std::shared_ptr<DataManagers::FontManager> DataManagers::StandardDataManager::getFontManager() const noexcept {
    return _fontManager;
}

std::shared_ptr<DataManagers::LogManager> DataManagers::StandardDataManager::getLogManager() const noexcept {
    return _logManager;
}

std::shared_ptr<DataManagers::TextureManager> DataManagers::StandardDataManager::getTextureManager() const noexcept {
    return _textureManager;
}