//
// Created by roman on 01.11.2020.
//

#ifndef FLASH_RECTANGLE_H
#define FLASH_RECTANGLE_H

#include "../Rotatable.h"
#include "RectangleGetters.h"
#include "RectangleSetters.h"

namespace Possibilities {

    /**
     * @brief The interface describes all possible methods of the rectangle.
     * @namespace Possibilities
     *
     * This class defines base Rectangle interface.
    */
    class Rectangle : public RectangleGetters, public RectangleSetters, public Rotatable {
    public:
        Rectangle() = default;

        virtual ~Rectangle() = default;
    };
}

#endif //FLASH_RECTANGLE_H
