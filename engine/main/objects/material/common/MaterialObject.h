//
// Created by roman on 18.09.2020.
//

#ifndef FLASH_MATERIALOBJECT_H
#define FLASH_MATERIALOBJECT_H

#include "../../auxiliary/possibilities/SelfActionable.h"
#include "../../auxiliary/possibilities/Movable.h"
#include "../../auxiliary/possibilities/Moving.h"
#include "../../auxiliary/possibilities/collision/CollisionProne.h"
#include "../../auxiliary/possibilities/coordinates/PhysicallySituated.h"
#include "../../auxiliary/possibilities/Drawable.h"
#include "properties/MaterialProperties.h"

namespace Unite {
    class Unifier;
}

namespace Material {

    /**
     * @brief The base class of the MaterialObject class hierarchy. Interface describes all material objects possibilities.
     * @namespace Material
     *
     * This class defines base MaterialObject interface.
    */
    class MaterialObject :
            public Possibilities::SelfActionable<Unite::Unifier>,
            public Possibilities::Movable,
            public Possibilities::Moving,
            public Possibilities::CollisionProne,
            public Possibilities::PhysicallySituated,
            public Possibilities::Drawable<sf::RenderTarget> {
    public:

        /**
         * @brief Default constructor.
         */
        MaterialObject(const MaterialProperties &material_properties);

        /**
         * @brief Constructor that allows you to initiate an object of arbitrary shape.
         * @param material_properties Material properties.
         * @param coordinates Object coordinates.
         */
        explicit MaterialObject(const MaterialProperties &material_properties, const Components::Coordinates &coordinates);

        /**
         * @brief Method updated coordinates value.
         */
        virtual void updateCoordinates() noexcept;

        /**
         * @brief Method contains personal object update location logic.
         */
        virtual void updateLocation() noexcept;

        /**
         * @brief Base collsion realization for material objects.
         */
        bool collision(float x, float y) const noexcept override;

        bool collision(const PhysicallySituated &object) const noexcept override;

        void move(float offsetX, float offsetY) noexcept override;

        void addSpeed(float offsetX, float offsetY) noexcept override;

        void setSpeed(const Components::Speed &speed) noexcept override;

        void setXSpeed(float xSpeed) noexcept override;

        void setYSpeed(float ySpeed) noexcept override;

        const Components::Speed &getSpeed() const noexcept override;

        const Components::Coordinates &getCoordinates() const noexcept override;

        const MaterialProperties &getMaterialProperties() const;

        virtual ~MaterialObject() = default;

    protected:
        Components::Coordinates m_coordinates;
        MaterialProperties m_material_properties;
    };
}

/**
 * These preprocessor directives are necessary for successful compilation.
 * When adding a new branch of material objects, additional directives should be added.
 */
#ifndef FLASH_MOB_H
#ifndef FLASH_OBSTACLE_H
#ifndef FLASH_PARTICLE_H

#include "../../unifier/common/Unifier.h"

#endif
#endif
#endif

#endif //FLASH_MATERIALOBJECT_H
