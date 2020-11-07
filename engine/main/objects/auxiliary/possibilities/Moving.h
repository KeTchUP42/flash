//
// Created by roman on 27.08.2020.
//

#ifndef FLASH_MOVING_H
#define FLASH_MOVING_H

namespace Possibilities {

    /**
     * @brief The base class of the Moving class hierarchy.
     * @namespace Possibilities
     *
     * This class defines base Moving interface.
    */
    class Moving {
    public:
        Moving() = default;

        /**
         * @brief Simple interface method to move object to current coordinates.
         * @param offsetX X offset.
         * @param offsetY Y offset.
         */
        virtual void move(float offsetX, float offsetY) noexcept = 0;

        virtual ~Moving() = default;
    };
}

#endif //FLASH_MOVING_H
