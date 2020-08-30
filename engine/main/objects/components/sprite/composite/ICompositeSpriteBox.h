//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_ICOMPOSITESPRITEBOX_H
#define FLASH_ICOMPOSITESPRITEBOX_H

#include "../sprite-box/ISpriteBox.h"

#include <memory>

namespace Components {

    /**
     * @brief The base class of the ICompositeSpriteBox class hierarchy.
     * @namespace Components
     *
     * This class is a base composite component interface.
    */
    class ICompositeSpriteBox
            : public Capabilities::Drawable,
              public Capabilities::Movable,
              public Capabilities::CollisionProne,
              public WindowView::Observer<sf::RenderWindow, sf::Event> {
    public:
        ICompositeSpriteBox() = default;

        /**
         * @brief Method deletes operator= method.
         * @return ICompositeSpriteBox&
         */
        ICompositeSpriteBox &operator=(const ICompositeSpriteBox &) = delete;

        /**
         * @brief Method adds new sprite box.
         * @param spriteBox ISpriteBox*
         */
        virtual void addSpriteBox(ISpriteBox *spriteBox) noexcept = 0;

        /**
         * @brief Method adds new sprite box.
         * @param spriteBox const std::shared_ptr<ISpriteBox>&
         */
        virtual void addSpriteBox(const std::shared_ptr<ISpriteBox> &spriteBox) noexcept = 0;

        /**
         * @brief Method removes sprite box.
         * @param spriteBox const std::shared_ptr<ISpriteBox>&
         */
        virtual void removeSpriteBox(const std::shared_ptr<ISpriteBox> &spriteBox) noexcept = 0;

        virtual ~ICompositeSpriteBox() = default;
    };
}

#endif //FLASH_ICOMPOSITESPRITEBOX_H
