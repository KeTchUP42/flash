//
// Created by roman on 10.10.2020.
//

#ifndef FLASH_JUMPINGPLAYERPROPERTIES_H
#define FLASH_JUMPINGPLAYERPROPERTIES_H

#include "../../../../../common/properties/ParamsTypes.h"

namespace Mobs {

    /**
     * @brief Struct contains all jumping player numeric properties.
     */
    struct JumpingPlayerProperties {
        JumpingPlayerProperties(
                Material::FRAC_PARAM moveSpeed,
                Material::FRAC_PARAM maxMoveSpeed,
                Material::FRAC_PARAM jumpSpeed
        ) : moveSpeed(moveSpeed),
            maxMoveSpeed(maxMoveSpeed),
            jumpSpeed(jumpSpeed) {}

        /**
         * @brief Speed increase at the push of a button.
         */
        Material::FRAC_PARAM moveSpeed;

        /**
         * @brief Maximum speed that a player can achieve when moving independently.
         */
        Material::FRAC_PARAM maxMoveSpeed;

        /**
         * @brief Speed obtained by jumping.
         */
        Material::FRAC_PARAM jumpSpeed;
    };
}

#endif //FLASH_JUMPINGPLAYERPROPERTIES_H
