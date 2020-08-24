//
// Created by roman on 23.08.2020.
//

#ifndef FLASH_SETUPER_H
#define FLASH_SETUPER_H

#include <string>

#include "../main/data/manager/DataManager.h"

namespace Setup {

    /**
     * @brief The base class of the Setuper class hierarchy.
     * @namespace Setup
     *
     * This class defines base Setuper interface.
    */
    class Setuper {
    public:
        explicit Setuper(const std::string &filename)
                : _configPath(filename) {}

        explicit Setuper(const char *filename)
                : _configPath(filename) {}

        /**
         * @brief Method converts config data to DataManager.
         * @return Managers::DataManager*
         */
        virtual DataManagers::DataManager *load() const = 0;

        virtual ~Setuper() = default;

    protected:
        const std::string _configPath;
    };
}

#endif //FLASH_SETUPER_H
