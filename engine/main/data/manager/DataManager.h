//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_DATAMANAGER_H
#define FLASH_DATAMANAGER_H

#include <memory>

#include "log-manager/LogManager.h"
#include "audio-manager/AudioManager.h"
#include "config-manager/ConfigManager.h"
#include "texture-manager/TextureManager.h"
#include "font-manager/FontManager.h"
#include "scene-manager/SceneManager.h"

namespace Managers {

    /**
     * @brief The base class of the DataManager class hierarchy. Facade class.
     * @namespace Managers
     *
     * This class defines base DataManager interface. DataManager contains all other managers for ease of use.
    */
    class DataManager {
    public:
        explicit DataManager(AudioManager *audioManager, ConfigManager *configManager, FontManager *fontManager,
                             LogManager *logManager, SceneManager *sceneManager, TextureManager *textureManager);

        explicit DataManager(const std::shared_ptr<AudioManager> &audioManager, const std::shared_ptr<ConfigManager> &configManager,
                             const std::shared_ptr<FontManager> &fontManager, const std::shared_ptr<LogManager> &logManager,
                             const std::shared_ptr<SceneManager> &sceneManager, const std::shared_ptr<TextureManager> &textureManager);

        /**
         * @brief Method returns AudioManager.
         * @return AudioManager
         */
        const std::shared_ptr<AudioManager> &getAudioManager() const noexcept;

        /**
         * @brief Method returns ConfigManager.
         * @return ConfigManager
         */
        const std::shared_ptr<ConfigManager> &getConfigManager() const noexcept;

        /**
         * @brief Method returns FontManager.
         * @return FontManager
         */
        const std::shared_ptr<FontManager> &getFontManager() const noexcept;

        /**
         * @brief Method returns LogManager.
         * @return LogManager
         */
        const std::shared_ptr<LogManager> &getLogManager() const noexcept;

        /**
         * @brief Method returns SceneManager.
         * @return SceneManager
         */
        const std::shared_ptr<SceneManager> &getSceneManager() const noexcept;

        /**
         * @brief Method returns TextureManager.
         * @return TextureManager
         */
        const std::shared_ptr<TextureManager> &getTextureManager() const noexcept;

        virtual ~DataManager() = default;

    private:
        std::shared_ptr<AudioManager> m_audioManager;
        std::shared_ptr<ConfigManager> m_configManager;
        std::shared_ptr<FontManager> m_fontManager;
        std::shared_ptr<LogManager> m_logManager;
        std::shared_ptr<SceneManager> m_sceneManager;
        std::shared_ptr<TextureManager> m_textureManager;
    };
}
#endif //FLASH_DATAMANAGER_H
