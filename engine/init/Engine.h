//
// Created by roman on 02.08.2020.
//

#ifndef FLASH_ENGINE_H
#define FLASH_ENGINE_H

#include "../main/data/manager/DataManager.h"

namespace Program {

    /**
     * @brief The class is the most important class in the program, and also includes an entry point.
     * @namespace Program
     *
     * This class has app entry point method.
    */
    class Engine final {
    public:
        /**
         * @brief Main app constructor.
         * @param filename Path to main ini config.
         */
        Engine(const std::string &filename);

        /**
         * @brief Main program entry point method.
         * @return LOG
         */
        int start() const;

        ~Engine();

    private:
        /**
         * @brief Window config file path.
         */
        std::string m_WindowSettingsFile;
        /**
         * @brief Pointer with unique data manager object. Uses to search app data.
         */
        Managers::DataManager *m_manager;
    };
}

#endif //FLASH_ENGINE_H
