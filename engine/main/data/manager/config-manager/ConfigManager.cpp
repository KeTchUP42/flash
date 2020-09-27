//
// Created by roman on 27.09.2020.
//

#include "ConfigManager.h"
#include "../../../../utils/Ini/BasicIniProcessor.h"

IniProcessorUtil::Analyzer::IniData Managers::ConfigManager::loadIni(const std::string &filename) const {
    IniProcessorUtil::BasicIniProcessor processor(CONFIG_DIRECTORY + "/" + filename);
    return processor.fullparse();
}