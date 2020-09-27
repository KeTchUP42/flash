//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_ENGINECONFIGURATOR_H
#define FLASH_ENGINECONFIGURATOR_H

#include <string>

#include "../main/data/manager/DataManager.h"

namespace Setup {

    /**
     * @brief The EngineConfigurator class.
     * @namespace Setup
     *
     * This class defines EngineConfigurator.
    */
    class EngineConfigurator {
    public:
        /**
         * @brief Method reads config and returns data managers in DataManager facade class object.
         * @return Created data manager.
         */
        virtual Managers::DataManager *load(const std::string &filename) const;

        virtual ~EngineConfigurator() = default;
    };
}

#endif //FLASH_ENGINECONFIGURATOR_H
