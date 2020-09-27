//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_ENGINECONFIGURATOR_H
#define FLASH_ENGINECONFIGURATOR_H

#include <string>

#include "../main/data/manager/DataManager.h"

namespace Setup {

    /**
     * @brief The base class of the EngineConfigurator class hierarchy.
     * @namespace Setup
     *
     * This class defines base EngineConfigurator interface and fields.
    */
    class EngineConfigurator {
    public:
        explicit EngineConfigurator(const std::string &filename)
                : CONFIG_FILE_NAME(filename) {}

        /**
         * @brief Method reads config and returns data managers in DataManager facade class object.
         * @return Created data manager.
         */
        virtual Managers::DataManager *load() const;

        virtual ~EngineConfigurator() = default;

    protected:
        const std::string CONFIG_FILE_NAME;
    };
}

#endif //FLASH_ENGINECONFIGURATOR_H
