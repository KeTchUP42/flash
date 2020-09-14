//
// Created by roman on 24.08.2020.
//

#include "IniConfigManager.h"
#include "../../../../utils/Ini/BasicIniProcessor.h"

IniProcessorUtil::Analyzer::IniData Managers::IniConfigManager::loadIni(const std::string &filename) const {
    IniProcessorUtil::BasicIniProcessor processor(CONFIG_DIRECTORY + "/" + filename);
    return processor.fullparse();
}
