//
// Created by roman on 02.08.2020.
//

#ifndef FLASH_KERNEL_H
#define FLASH_KERNEL_H

namespace Engine {

    /**
     *  @brief  App main class and entry point.
     *  @namespace Engine
     *
     *  This class has app entry point method.
    */
    class Kernel {
    public:
        typedef int KERNEL_LOG;

        KERNEL_LOG run() const noexcept;

        virtual ~Kernel() = default;
    };
}

#endif //FLASH_KERNEL_H
