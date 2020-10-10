//
// Created by roman on 10.10.2020.
//

#ifndef FLASH_COORDINATESGETTERS_H
#define FLASH_COORDINATESGETTERS_H

#include "../components/elementary/Coordinates.h"

namespace Possibilities {

    /**
     * @brief The interface describes methods that give access to data allowing to describe a object with cached coordinates.
     * @namespace Possibilities
     *
     * This class defines base CoordinatesGetters interface.
    */
    class CoordinatesGetters {
    public:
        CoordinatesGetters() = default;

        /**
         * @brief Method return object current coordinates.
         * @return Coordinates.
         */
        virtual const Components::Coordinates &getCoordinates() const noexcept = 0;

        virtual ~CoordinatesGetters() = default;
    };
}

#endif //FLASH_COORDINATESGETTERS_H
