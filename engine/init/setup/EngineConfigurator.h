//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_ENGINECONFIGURATOR_H
#define FLASH_ENGINECONFIGURATOR_H

#include <string>

#include "../../main/data/manager/DataManager.h"

namespace Setup {

    /**
     * @brief The class contains configuration logic for the engine.
     * @namespace Setup
     *
     * This class defines EngineConfigurator.
    */
    class EngineConfigurator {
    public:
        EngineConfigurator() = default;

        /**
         * @brief Method reads data block and returns data managers in DataManager facade class object.
         * @return Created data manager.
         */
        Managers::DataManager *loadDataManager(const IniUtil::Analyzer::IniBlock &block) const;

        virtual ~EngineConfigurator() = default;
    };
}

#endif //FLASH_ENGINECONFIGURATOR_H
