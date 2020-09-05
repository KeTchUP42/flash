//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_CONFIGURATOR_H
#define FLASH_CONFIGURATOR_H

#include <string>

#include "../main/data/manager/DataManager.h"

namespace Setup {

    /**
     * @brief The base class of the Configurator class hierarchy.
     * @namespace Setup
     *
     * This class defines base Configurator interface and fields.
    */
    class Configurator {
    public:
        explicit Configurator(const std::string &filename)
                : _config(filename) {}

        /**
         * @brief Method reads config and returns data managers in DataManager facade class.
         * @return Created data manager.
         */
        virtual Managers::DataManager *load() const = 0;

        virtual ~Configurator() = default;

    protected:
        const std::string _config;
    };
}

#endif //FLASH_CONFIGURATOR_H
