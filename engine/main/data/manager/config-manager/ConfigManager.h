//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_CONFIGMANAGER_H
#define FLASH_CONFIGMANAGER_H

#include <string>

#include "../../../../utils/Ini/analyzer/Analyzer.h"

namespace Managers {

    /**
     * @brief The base class of the ConfigManager class hierarchy.
     * @namespace Managers
     *
     * This class defines base ConfigManager interface and fields.
     */
    class ConfigManager {
    public:
        explicit ConfigManager(const std::string &configDirectory)
                : CONFIG_DIRECTORY(configDirectory) {}

        explicit ConfigManager(const char *configDirectory)
                : CONFIG_DIRECTORY(configDirectory) {}

        /**
         * @brief Method loads and analizes ini config file.
         * @param filename File in config directory.
         * @return IniUtil::Analyzer::IniData
         */
        IniUtil::Analyzer::IniData loadIni(const std::string &filename) const;

        virtual ~ConfigManager() = default;

    private:
        const std::string CONFIG_DIRECTORY;
    };
}

#endif //FLASH_CONFIGMANAGER_H
