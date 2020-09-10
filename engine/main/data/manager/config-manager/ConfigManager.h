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
                : _configs(configDirectory) {}

        explicit ConfigManager(const char *configDirectory)
                : _configs(configDirectory) {}

        /**
         * @brief Method loads and analizes ini config file.
         * @param filename File in config directory.
         * @return IniProcessorUtil::Analyzer::IniData
         */
        virtual IniProcessorUtil::Analyzer::IniData loadIni(const std::string &filename) const = 0;

        virtual ~ConfigManager() = default;

    protected:
        const std::string _configs;
    };
}

#endif //FLASH_CONFIGMANAGER_H
