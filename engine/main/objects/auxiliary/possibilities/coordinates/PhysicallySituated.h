//
// Created by roman on 10.10.2020.
//

#ifndef FLASH_PHYSICALLYSITUATED_H
#define FLASH_PHYSICALLYSITUATED_H

#include "../../components/elementary/coordinates/Coordinates.h"

namespace Possibilities {

    /**
     * @brief The interface describes methods that give access to data allowing to describe a object with cached coordinates.
     * @namespace Possibilities
     *
     * This class defines base PhysicallySituated interface.
    */
    class PhysicallySituated {
    public:
        PhysicallySituated() = default;

        /**
         * @brief Method return object current coordinates.
         * @return Coordinates.
         */
        virtual const Components::Coordinates &getCoordinates() const noexcept = 0;

        virtual ~PhysicallySituated() = default;
    };
}

#endif //FLASH_PHYSICALLYSITUATED_H
