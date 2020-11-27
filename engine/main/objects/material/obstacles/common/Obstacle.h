//
// Created by roman on 11.09.2020.
//

#ifndef FLASH_OBSTACLE_H
#define FLASH_OBSTACLE_H

#include "../../../auxiliary/possibilities/Peculiar.h"
#include "properties/ObstacleProperties.h"
#include "../../common/MaterialObject.h"

namespace Obstacles {

    /**
     * @brief The base class of the Obstacle class hierarchy. It contains all usefull interfaces.
     * @namespace Obstacles
     *
     * This class defines base Obstacle interface and realization.
    */
    class Obstacle : public Material::MaterialObject,
                     public Possibilities::Peculiar<Obstacles::ObstacleProperties> {
    public:
        /**
         * @brief Main obstacle constructor.
         * @param properties Object with obstacle properties.
         */
        Obstacle(const ObstacleProperties &properties);

        void addSpeed(float offsetX, float offsetY) noexcept override;

        void setXSpeed(float xSpeed) noexcept override;

        void setYSpeed(float ySpeed) noexcept override;

        void setSpeed(const Components::Speed &speed) noexcept override;

        const Components::Speed &getSpeed() const noexcept override;

        const ObstacleProperties &getProperties() const noexcept override;

        virtual ~Obstacle() = default;

    protected:
        ObstacleProperties m_properties;
    };
}

#include "../../../unifier/common/Unifier.h"

#endif //FLASH_OBSTACLE_H
