//
// Created by roman on 24.08.2020.
//

#include "IniConfigManager.h"
#include "../../../../utils/Ini/BaseIniProcessor.h"

IniProcessorUtil::Analyzer::IniData Managers::IniConfigManager::loadIni(const std::string &filename) const {
    IniProcessorUtil::BaseIniProcessor processor(_configs + "/" + filename);
    return processor.fullparse();
}
