//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_POINT_H
#define FLASH_POINT_H

namespace Components {

    /**
     * @brief Base component.
     * @namespace Components
     *
     * This struct is the base component.
    */
    struct Point {
        explicit Point(float x, float y)
                : x(x), y(y) {}

        float x;
        float y;
    };
}

#endif //FLASH_POINT_H
