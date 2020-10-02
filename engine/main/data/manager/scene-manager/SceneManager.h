//
// Created by roman on 29.09.2020.
//

#ifndef FLASH_SCENEMANAGER_H
#define FLASH_SCENEMANAGER_H

#include <string>
#include "../../../../utils/Ini/analyzer/Analyzer.h"

namespace Managers {

    /**
     * @brief The base class of the SceneManager class hierarchy.
     * @namespace Managers
     *
     * This class defines base SceneManager interface.
     */
    class SceneManager {
    public:
        explicit SceneManager(const std::string &sceneDirectory)
                : SCENE_DIRECTORY(sceneDirectory) {}

        explicit SceneManager(const char *sceneDirectory)
                : SCENE_DIRECTORY(sceneDirectory) {}

        /**
         * @brief Method loads and analizes scene ini config file.
         * @param filename File in scene directory.
         * @return IniUtil::Analyzer::IniData
         */
        IniUtil::Analyzer::IniData load(const std::string &filename) const;

        virtual ~SceneManager() = default;

    protected:
        const std::string SCENE_DIRECTORY;
    };
}

#endif //FLASH_SCENEMANAGER_H
