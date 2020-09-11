//
// Created by roman on 09.09.2020.
//

#ifndef FLASH_SPEED_H
#define FLASH_SPEED_H

namespace Components {

    /**
     * @brief Base component.
     * @namespace Components
     *
     * This struct is the base component.
    */
    struct Speed {
        Speed(float xSpeed, float ySpeed)
                : xSpeed(xSpeed), ySpeed(ySpeed) {}

        Speed() : xSpeed(), ySpeed() {}

        float xSpeed;
        float ySpeed;
    };
}

#endif //FLASH_SPEED_H
