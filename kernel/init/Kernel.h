//
// Created by roman on 02.08.2020.
//

#ifndef FLASH_KERNEL_H
#define FLASH_KERNEL_H

namespace Engine {

    class Kernel {
    public:
        typedef int KERNEL_LOG;

        /*
         * todo: Change kernel construntor
         */
        Kernel() = default;

        KERNEL_LOG run() const noexcept;

        virtual ~Kernel() = default;
    };
}

#endif //FLASH_KERNEL_H
