//
// Created by roman on 02.08.2020.
//

#ifndef FLASH_ENGINE_H
#define FLASH_ENGINE_H

#include "../main/data/manager/DataManager.h"

#include <string>
#include <memory>

namespace Program {

    /**
     * @brief App main class and entry point.
     * @namespace Program
     *
     * This class has app entry point method.
    */
    class Engine {
    public:

        /**
         * @brief Main app constructor.
         * @param filename - path to main ini config.
         */
        explicit Engine(const std::string &filename);

        /**
         * @brief Main program entry point method.
         * @return LOG
         */
        int start() const;

        virtual ~Engine() = default;

    private:

        /**
         * @brief Pointer with unique data manager object. Uses to search app data.
         */
        std::unique_ptr<Managers::DataManager> _manager;
    };
}

#endif //FLASH_ENGINE_H
