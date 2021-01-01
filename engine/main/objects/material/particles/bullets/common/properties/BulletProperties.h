//
// Created by roman on 29.11.2020.
//

#ifndef FLASH_BULLETPROPERTIES_H
#define FLASH_BULLETPROPERTIES_H

namespace Particles {

    /**
     * @brief Struct contains all bullet numeric properties.
     */
    struct BulletProperties {
        explicit BulletProperties(float damage) : damage(damage) {}

        /**
         * @brief Bullet's damage.
         */
        float damage;
    };
}

#endif //FLASH_BULLETPROPERTIES_H
