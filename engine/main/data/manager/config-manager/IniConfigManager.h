//
// Created by roman on 24.08.2020.
//

#ifndef FLASH_INICONFIGMANAGER_H
#define FLASH_INICONFIGMANAGER_H

#include "ConfigManager.h"

namespace Managers {

    class IniConfigManager : public ConfigManager {
    public:
        explicit IniConfigManager(const std::string &configDirectory)
                : ConfigManager(configDirectory) {}

        explicit IniConfigManager(const char *configDirectory)
                : ConfigManager(configDirectory) {}

        IniProcessorUtil::Analyzer::IniData loadIni(const std::string &filename) const override;
    };
}

#endif //FLASH_INICONFIGMANAGER_H
