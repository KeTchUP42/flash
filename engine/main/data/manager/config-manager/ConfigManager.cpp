//
// Created by roman on 27.09.2020.
//

#include "ConfigManager.h"
#include "../../../../utils/Ini/BasicIniProcessor.h"

IniUtil::Analyzer::IniData Managers::ConfigManager::loadIni(const std::string &filename) const {
    IniUtil::BasicIniProcessor processor(CONFIG_DIRECTORY + "/" + filename);
    return processor.fullparse();
}