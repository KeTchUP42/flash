//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_ISPRITE_H
#define FLASH_ISPRITE_H

#include "../../../possibilities/Moving.h"
#include "../../../possibilities/Rotatable.h"
#include "../../../possibilities/Drawable.h"

namespace Components {

    /**
     * @brief The base class of the ISprite class hierarchy. Basic interface for all sprite classes.
     * @namespace Components
     *
     * This class is a base leaf component interface.
    */
    class ISprite : public Possibilities::Moving,
                    public Possibilities::Rotatable,
                    public Possibilities::Drawable<sf::RenderTarget> {
    public:

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
        Components::ISprite *m_parent;
    };
}

#endif //FLASH_ISPRITE_H
