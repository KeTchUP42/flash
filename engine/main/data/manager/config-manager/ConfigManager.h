//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_CONFIGMANAGER_H
#define FLASH_CONFIGMANAGER_H

#include <string>

#include "../../../../utils/Ini/analyzer/Analyzer.h"

namespace DataManagers {

    /**
     * @brief The base class of the ConfigManager class hierarchy.
     * @namespace DataManagers
     *
     * This class defines base ConfigManager interface.
     */
    class ConfigManager {
    public:
        explicit ConfigManager(const std::string &configDirectory)
                : _configDirectory(configDirectory) {}

        explicit ConfigManager(const char *configDirectory)
                : _configDirectory(configDirectory) {}

        using ConfigDataType = IniProcessorUtil::Analyzer::IniData;

        /**
         * @brief Method loads and analize config file.
         * @param filename File in config directory.
         * @return ConfigDataType
         */
        virtual ConfigDataType load(const std::string &filename) const = 0;

        virtual ~ConfigManager() = default;

    protected:
        const std::string _configDirectory;
    };
}

#endif //FLASH_CONFIGMANAGER_H
