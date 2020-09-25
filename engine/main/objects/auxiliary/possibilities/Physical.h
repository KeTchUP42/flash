//
// Created by roman on 15.09.2020.
//

#ifndef FLASH_PHYSICAL_H
#define FLASH_PHYSICAL_H

#include "../../material/common/properties/MaterialProperties.h"

namespace Possibilities {

    /**
     * @brief The base class of the Physical class hierarchy.
     * @namespace Possibilities
     *
     * This class defines base Physical interface.
    */
    class Physical {
    public:
        Physical() = default;

        /**
         * @brief Method returns object's properties.
         * @return Physical properties.
         */
        virtual const Material::MaterialProperties &getProperties() const noexcept = 0;

        virtual ~Physical() = default;
    };
}

#endif //FLASH_PHYSICAL_H
