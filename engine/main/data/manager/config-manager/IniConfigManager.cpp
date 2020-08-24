//
// Created by roman on 24.08.2020.
//

#include "IniConfigManager.h"
#include "../../../../utils/Ini/BaseIniProcessor.h"

IniProcessorUtil::Analyzer::IniData DataManagers::IniConfigManager::load(const std::string &filename) const {
    IniProcessorUtil::BaseIniProcessor processor(_configDirectory + "/" + filename);
    return std::move(processor.fullparse());
}
