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

        float moveSpeed;
        float maxMoveSpeed;
        float jumpSpeed;
    };
}

#endif //FLASH_BASICPLAYERPROPERTIES_H
