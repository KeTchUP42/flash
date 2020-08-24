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

namespace DataManagers {

    /**
     * @brief The base class of the DataManager class hierarchy. Facade class interface.
     * @namespace DataManagers
     *
     * This class defines base DataManager interface.
    */
    class DataManager {
    public:
        DataManager() = default;

        /**
         * @brief Method returns AudioManager.
         * @return std::shared_ptr<AudioManager>
         */
        virtual std::shared_ptr<AudioManager> getAudioManager() const noexcept = 0;

        /**
         * @brief Method returns ConfigManager.
         * @return std::shared_ptr<ConfigManager>
         */
        virtual std::shared_ptr<ConfigManager> getConfigManager() const noexcept = 0;


        /**
         * @brief Method returns FontManager.
         * @return std::shared_ptr<FontManager>
         */
        virtual std::shared_ptr<FontManager> getFontManager() const noexcept = 0;

        /**
         * @brief Method returns LogManager.
         * @return std::shared_ptr<LogManager>
         */
        virtual std::shared_ptr<LogManager> getLogManager() const noexcept = 0;

        /**
         * @brief Method returns TextureManager.
         * @return std::shared_ptr<TextureManager>
         */
        virtual std::shared_ptr<TextureManager> getTextureManager() const noexcept = 0;

        virtual ~DataManager() = default;
    };
}
#endif //FLASH_DATAMANAGER_H
