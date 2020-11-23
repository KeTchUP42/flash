//
// Created by roman on 22.11.2020.
//

#ifndef FLASH_SLIMEPROPERTIES_H
#define FLASH_SLIMEPROPERTIES_H

namespace Mobs {

    /**
     * @brief Struct contains slime numeric properties.
     */
    struct SlimeProperties {
        explicit SlimeProperties(
                float moveSpeed,
                float jumpSpeed,
                unsigned jumpRate,
                float punchPower,
                float punchDamage,
                float elasticCoefficient,
                float frictionCoefficient,
                unsigned minSplitSize
        ) : moveSpeed(moveSpeed),
            jumpSpeed(jumpSpeed),
            jumpRate(jumpRate),
            punchPower(punchPower),
            punchDamage(punchDamage),
            elasticCoefficient(elasticCoefficient),
            frictionCoefficient(frictionCoefficient),
            minSplitSize(minSplitSize) {}

        float moveSpeed;
        float jumpSpeed;
        unsigned jumpRate;
        float punchPower;
        float punchDamage;
        float elasticCoefficient;
        float frictionCoefficient;
        unsigned minSplitSize;
    };
}

#endif //FLASH_SLIMEPROPERTIES_H
