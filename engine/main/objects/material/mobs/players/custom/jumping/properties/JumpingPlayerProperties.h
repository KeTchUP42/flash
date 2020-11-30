//
// Created by roman on 10.10.2020.
//

#ifndef FLASH_JUMPINGPLAYERPROPERTIES_H
#define FLASH_JUMPINGPLAYERPROPERTIES_H

namespace Mobs {

    /**
     * @brief Struct contains all jumping player numeric properties.
     */
    struct JumpingPlayerProperties {
        explicit JumpingPlayerProperties(
                float moveSpeed,
                float maxMoveSpeed,
                float jumpSpeed
        ) : moveSpeed(moveSpeed),
            maxMoveSpeed(maxMoveSpeed),
            jumpSpeed(jumpSpeed) {}

        /**
         * @brief Speed increase at the push of a button.
         */
        float moveSpeed;

        /**
         * @brief Maximum speed that a player can achieve when moving independently.
         */
        float maxMoveSpeed;

        /**
         * @brief Speed obtained by jumping.
         */
        float jumpSpeed;
    };
}

#endif //FLASH_JUMPINGPLAYERPROPERTIES_H
