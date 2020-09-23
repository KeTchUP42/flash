//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_ISPRITE_H
#define FLASH_ISPRITE_H

#include "../../../possibilities/Drawable.h"
#include "../../../possibilities/Movable.h"
#include "../../../possibilities/Rotatable.h"
#include "../../../possibilities/CollisionProne.h"
#include "../../../../../view/windows/base/observer/Observer.h"
#include "../../elementary/point/Point.h"
#include "../../elementary/Size.h"

#include <SFML/Graphics.hpp>

namespace Components {

    /**
     * @brief The base class of the ISprite class hierarchy.
     * @namespace Components
     *
     * This class is a base leaf component interface.
    */
    class ISprite
            : public Possibilities::Movable,
              public Possibilities::Rotatable,
              public Possibilities::CollisionProne,
              public Possibilities::Drawable<sf::RenderTarget>,
              public WindowView::Observer<sf::RenderWindow, sf::Event> {
    public:
        ISprite() = default;

        /**
         * @brief Method deletes operator= method.
         * @return ISprite&
         */
        ISprite &operator=(const ISprite &) = delete;

        /**
         * @brief Method sets new tree parent for sprite.
         * @param sprite New parent.
         */
        void setParent(Components::ISprite *sprite) noexcept;

        /**
         * @brief Method returns sprites parent.
         * @return Sprite's parent.
         */
        Components::ISprite *getParent() const noexcept;

        virtual ~ISprite() = default;

    protected:
        /**
         * @brief Sprite's tree parent. Base sprite will not have parent, so it will be "nullptr".
         */
        Components::ISprite *_parent;
    };
}

#endif //FLASH_ISPRITE_H
