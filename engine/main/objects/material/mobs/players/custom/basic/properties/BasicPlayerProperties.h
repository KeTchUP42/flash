//
// Created by roman on 10.10.2020.
//

#ifndef FLASH_BASICPLAYERPROPERTIES_H
#define FLASH_BASICPLAYERPROPERTIES_H

namespace Mobs {

    /**
     * @brief Struct contains all basic player numeric properties.
     */
    struct BasicPlayerProperties {
        explicit BasicPlayerProperties(float moveSpeed, float maxMoveSpeed, float jumpSpeed)
                : moveSpeed(moveSpeed), maxMoveSpeed(maxMoveSpeed), jumpSpeed(jumpSpeed) {}

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

#endif //FLASH_BASICPLAYERPROPERTIES_H
