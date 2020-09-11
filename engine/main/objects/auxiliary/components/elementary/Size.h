//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_SIZE_H
#define FLASH_SIZE_H

namespace Components {

    /**
     * @brief Base component.
     * @namespace Components
     *
     * This struct is the base component.
    */
    struct Size {
        explicit Size(unsigned int width, unsigned int height)
                : width(width), height(height) {}

        Size() : width(), height() {}

        unsigned int width;
        unsigned int height;
    };
}

#endif //FLASH_SIZE_H
