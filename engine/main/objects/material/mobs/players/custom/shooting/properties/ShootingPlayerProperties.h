//
// Created by roman on 29.11.2020.
//

#ifndef FLASH_SHOOTINGPLAYERPROPERTIES_H
#define FLASH_SHOOTINGPLAYERPROPERTIES_H

#include <memory>
#include <SFML/Graphics/Texture.hpp>

#include "../../../../../../auxiliary/components/elementary/size/Size.h"

namespace Mobs {

    /**
     * @brief Struct type alias for data shortening.
     */
    typedef struct {
        Components::Size size;
        float angle;
    } NotFullAreaData;

    /**
     * @brief Struct contains all shooting player numeric properties.
     */
    struct ShootingPlayerProperties {
        ShootingPlayerProperties(
                float bulletsFlightSpeed,
                float bulletsDamage,
                bool bulletsUnderEffects,
                const NotFullAreaData &bulletData,
                const NotFullAreaData &bulletSpriteData,
                const std::shared_ptr<sf::Texture> &rightBulletsTexture,
                const std::shared_ptr<sf::Texture> &leftBulletsTexture
        ) : bulletsFlightSpeed(bulletsFlightSpeed),
            bulletsDamage(bulletsDamage),
            bulletsUnderEffects(bulletsUnderEffects),
            bulletsData(bulletData),
            bulletsSpriteData(bulletSpriteData),
            rightBulletsTexture(rightBulletsTexture),
            leftBulletsTexture(leftBulletsTexture) {}

        /**
         * @brief Bullets flight speed.
         */
        float bulletsFlightSpeed;

        /**
         * @brief Bullets damage.
         */
        float bulletsDamage;

        /**
         * @brief The flag controls the effect of static effects on bullets.
         */
        bool bulletsUnderEffects;

        /**
         * @brief Bullets data.
         */
        NotFullAreaData bulletsData;

        /**
         * @brief Bullets sprite data.
         */
        NotFullAreaData bulletsSpriteData;

        /**
         * @brief Right bullets texture.
         */
        std::shared_ptr<sf::Texture> rightBulletsTexture;

        /**
         * @brief Left bullets texture.
         */
        std::shared_ptr<sf::Texture> leftBulletsTexture;
    };
}

#endif //FLASH_SHOOTINGPLAYERPROPERTIES_H
