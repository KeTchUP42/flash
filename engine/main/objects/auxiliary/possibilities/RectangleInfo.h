//
// Created by roman on 10.10.2020.
//

#ifndef FLASH_RECTANGLEINFO_H
#define FLASH_RECTANGLEINFO_H

#include "CoordinatesGetters.h"
#include "RectangleGetters.h"

namespace Possibilities {

    /**
     * @brief The interface describes methods that give access to data allowing to describe a rectangle.
     * @namespace Possibilities
     *
     * This class defines base RectangleInfo interface.
    */
    class RectangleInfo : public RectangleGetters,
                          public CoordinatesGetters {
    public:
        RectangleInfo() = default;

        virtual ~RectangleInfo() = default;
    };
}

#endif //FLASH_RECTANGLEINFO_H
