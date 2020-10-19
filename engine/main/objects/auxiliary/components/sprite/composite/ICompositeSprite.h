//
// Created by roman on 30.08.2020.
//

#ifndef FLASH_ICOMPOSITESPRITE_H
#define FLASH_ICOMPOSITESPRITE_H

#include "../common-base/ISprite.h"

#include <memory>
#include <list>

namespace Components {

    /**
     * @brief The base class of the ICompositeSprite class hierarchy.
     * @namespace Components
     *
     * This class is a base composite component interface and realization.
    */
    class ICompositeSprite : public ISprite {
    public:
        ICompositeSprite() = default;

        /**
         * @brief Method adds new sprite.
         * @param sprite New sprite.
         */
        void addSprite(ISprite *sprite) noexcept;

        /**
         * @brief Method adds new sprite.
         * @param sprite New sprite.
         */
        void addSprite(const std::shared_ptr<ISprite> &sprite) noexcept;

        /**
         * @brief Method removes sprite.
         * @param sprite Existing sprite.
         */
        void removeSprite(ISprite *sprite) noexcept;

        /**
         * @brief Method removes sprite.
         * @param sprite Existing sprite.
         */
        void removeSprite(const std::shared_ptr<ISprite> &sprite) noexcept;

        virtual ~ICompositeSprite() = default;

    protected:
        std::list<std::shared_ptr<ISprite>> m_sprites;
    };
}

#endif //FLASH_ICOMPOSITESPRITE_H
