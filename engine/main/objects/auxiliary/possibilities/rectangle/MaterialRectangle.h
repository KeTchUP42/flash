//
// Created by roman on 01.11.2020.
//

#ifndef FLASH_MATERIALRECTANGLE_H
#define FLASH_MATERIALRECTANGLE_H

#include "RectangleGetters.h"
#include "../coordinates/PhysicallySituated.h"

namespace Possibilities {

    /**
     * @brief The interface describes methods that give access to data allowing to describe a rectangle with cached coordinates.
     * @namespace Possibilities
     *
     * This class defines base MaterialRectangle interface.
    */
    class MaterialRectangle : public RectangleGetters, public PhysicallySituated {
    public:
        MaterialRectangle() = default;

        virtual ~MaterialRectangle() = default;
    };
}


#endif //FLASH_MATERIALRECTANGLE_H
