//
// Created by roman on 18.09.2020.
//

#ifndef FLASH_MATERIALOBJECT_H
#define FLASH_MATERIALOBJECT_H

#include "../../auxiliary/possibilities/Drawable.h"
#include "../../auxiliary/possibilities/Movable.h"
#include "../../auxiliary/possibilities/CollisionProne.h"
#include "../../auxiliary/possibilities/Rotatable.h"
#include "../../auxiliary/possibilities/SelfActionable.h"
#include "../../auxiliary/possibilities/SelfMovable.h"
#include "../../../view/windows/base/observer/Observer.h"
#include "../../auxiliary/components/elementary/Size.h"
#include "../../auxiliary/possibilities/RectangleInfo.h"
#include "../../auxiliary/possibilities/RectangleSetters.h"
#include "../../../../utils/math/RectangleMath.h"

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
            public Possibilities::SelfMovable<Unite::Unifier>,
            public Possibilities::Movable,
            public Possibilities::CollisionProne,
            public Possibilities::Rotatable,
            public Possibilities::RectangleInfo,
            public Possibilities::RectangleSetters,
            public Possibilities::Drawable<sf::RenderTarget>,
            public WindowView::Observer<sf::RenderWindow, sf::Event> {
    public:
        MaterialObject();

        /**
         * @brief Method updated coordinates value.
         */
        void updateCoordinates() noexcept;

        /**
         * @brief Method contains personal object update location logic.
         */
        virtual void updateLocation() noexcept;

        /**
         * @brief Base collsion realization for material objects.
         */
        virtual bool collision(float x, float y) const noexcept override;

        virtual void update(const sf::Event &event, sf::RenderWindow &sender) override;

        const Components::Coordinates &getCoordinates() const noexcept override;

        virtual ~MaterialObject() = default;

    protected:
        Components::Coordinates m_coordinates;
    };
}

#include "../../unifier/common/Unifier.h"

#endif //FLASH_MATERIALOBJECT_H
