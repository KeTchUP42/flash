//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_POINT_H
#define FLASH_POINT_H

namespace Components {

    /**
     * @brief The base component struct.
     * @namespace Components
     *
     * This struct is a base objects component.
    */
    struct Point {
        explicit Point(int x, int y)
                : x(x), y(y) {}

        int x;
        int y;
    };
}

#endif //FLASH_POINT_H
