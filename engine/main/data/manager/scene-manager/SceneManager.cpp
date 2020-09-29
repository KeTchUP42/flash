//
// Created by roman on 29.09.2020.
//

#include "SceneManager.h"
#include "../../../../utils/Ini/BasicIniProcessor.h"

IniProcessorUtil::Analyzer::IniData Managers::SceneManager::load(const std::string &filename) const {
    IniProcessorUtil::BasicIniProcessor processor(SCENE_DIRECTORY + "/" + filename);
    return processor.fullparse();
}
