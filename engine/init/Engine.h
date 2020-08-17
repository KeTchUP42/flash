//
// Created by roman on 02.08.2020.
//

#ifndef FLASH_ENGINE_H
#define FLASH_ENGINE_H

namespace ProgramEngine {

    /**
     * @brief  App main class and entry point.
     * @namespace Engine
     *
     * This class has app entry point method.
    */
    class Engine {
    public:
        typedef int LOG;

        LOG start() const noexcept;

        virtual ~Engine() = default;
    };
}

#endif //FLASH_ENGINE_H
