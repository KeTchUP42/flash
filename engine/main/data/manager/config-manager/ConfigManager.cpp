//
// Created by roman on 27.09.2020.
//

#include "ConfigManager.h"
#include "../../../../utils/Ini/IniProcessor.h"

IniUtil::Analyzer::IniData Managers::ConfigManager::loadIni(const std::string &filename) const {
    IniUtil::IniProcessor processor(CONFIG_DIRECTORY + "/" + filename);
    return processor.fullparse();
}